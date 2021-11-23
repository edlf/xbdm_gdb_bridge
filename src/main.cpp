#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <vector>

#include "net/ip_address.h"
#include "shell/shell.h"
#include "xbox/xbox_interface.h"

#define DEFAULT_PORT 731

namespace logging = boost::log;
namespace po = boost::program_options;

static const std::string kCommandDelimiter{"&&"};

void validate(boost::any &v, const std::vector<std::string> &values,
              IPAddress *, int) {
  po::validators::check_first_occurrence(v);
  const std::string &value = po::validators::get_single_string(values);

  IPAddress addr(value, DEFAULT_PORT);
  v = boost::any(addr);
}

static int main_(const IPAddress &xbox_addr,
                 const std::vector<std::vector<std::string>> &commands,
                 bool run_shell) {
  BOOST_LOG_TRIVIAL(trace) << "Startup - XBDM @ " << xbox_addr;
  auto interface = std::make_shared<XBOXInterface>("XBOX", xbox_addr);
  interface->Start();

  auto shell = Shell(interface);
  for (auto &command : commands) {
    shell.ProcessCommand(command);
  }

  if (run_shell) {
    shell.Run();
  }

  interface->Stop();
  return 0;
}

// Splits the given vector of strings into sub-vectors delimited by
// kCommandDelimiter
static std::vector<std::vector<std::string>> split_commands(
    const std::vector<std::string> &additional_commands) {
  std::vector<std::vector<std::string>> ret;

  if (additional_commands.empty()) {
    return ret;
  }

  std::vector<std::string> cmd;
  for (auto &elem : additional_commands) {
    if (elem == "&&") {
      ret.push_back(cmd);
      cmd.clear();
      continue;
    }

    cmd.push_back(elem);
  }
  ret.push_back(cmd);

  return std::move(ret);
}

int main(int argc, char *argv[]) {
  bool run_shell;
  po::options_description opts("Options:");
  // clang-format off
  opts.add_options()
      ("help,?", po::bool_switch(), "Print this help message.")
      ("xbox", po::value<IPAddress>()->value_name("<IP[:Port]>"), "IP (and optionally Port) of the XBOX to connect to.")
      ("shell,s", po::bool_switch(&run_shell), "Run the shell even if an initial command is given.")
      ("verbosity,v", po::value<uint32_t>()->value_name("<level>")->default_value(0), "Sets logging verbosity.")
      ("command", po::value<std::vector<std::string>>()->multitoken(), "Optional command to run instead of running the shell.")
      ;
  // clang-format on

  po::positional_options_description positional;
  positional.add("xbox", 1);
  positional.add("command", -1);

  auto parsed = po::command_line_parser(argc, argv)
                    .allow_unregistered()
                    .options(opts)
                    .positional(positional)
                    .run();

  po::variables_map vm;
  try {
    po::store(parsed, vm);

    if (vm["help"].as<bool>()) {
      std::cout << opts << std::endl;
      return 1;
    }

    po::notify(vm);
  } catch (boost::program_options::error &e) {
    std::cout << "ERROR: " << e.what() << std::endl;
    std::cout << opts << std::endl;
    return 1;
  }

  if (!vm.count("xbox")) {
    std::cout << "Missing required 'xbox' parameter." << std::endl;
    std::cout << opts << std::endl;
    return 1;
  }

  IPAddress xbox_addr = vm["xbox"].as<IPAddress>();
  uint32_t verbosity = vm["verbosity"].as<uint32_t>();
  std::vector<std::string> additional_commands;
  auto command_params = vm.find("command");
  if (command_params != vm.end()) {
    additional_commands = command_params->second.as<std::vector<std::string>>();
  }

  logging::core::get()->set_filter(
      [verbosity](const boost::log::attribute_value_set &values) mutable {
        auto severity =
            values["Severity"].extract<logging::trivial::severity_level>();
        int info_level = logging::trivial::info;
        if (verbosity > info_level) {
          verbosity = info_level;
        } else if (info_level - verbosity > logging::trivial::fatal) {
          verbosity = info_level - logging::trivial::fatal;
        }
        return severity >= (logging::trivial::info - verbosity);
      });

  std::vector<std::vector<std::string>> commands =
      split_commands(additional_commands);

  return main_(xbox_addr, commands, run_shell || commands.empty());
}
