#include "shell.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

#include "commands.h"
#include "debugger_commands.h"
#include "shell_commands.h"

Shell::Shell(std::shared_ptr<XBOXInterface> &interface)
    : interface_(interface), prompt_("> ") {
#define REGISTER(command, handler) \
  commands_[command] = std::make_shared<handler>()

  auto quit = std::make_shared<ShellCommandQuit>();
  commands_["exit"] = quit;
  REGISTER("gdb", ShellCommandGDB);
  commands_["help"] = nullptr;
  commands_["?"] = nullptr;
  REGISTER("reconnect", ShellCommandReconnect);
  commands_["quit"] = quit;

  REGISTER("/launch", DebuggerCommandLaunch);
  REGISTER("/launchwait", DebuggerCommandLaunchWait);
  REGISTER("/attach", DebuggerCommandAttach);
  REGISTER("/detach", DebuggerCommandDetach);
  REGISTER("/restart", DebuggerCommandRestart);
  REGISTER("/switch", DebuggerCommandSetActiveThread);
  REGISTER("/threads", DebuggerCommandGetThreads);
  REGISTER("/info", DebuggerCommandGetThreadInfo);
  REGISTER("/stepi", DebuggerCommandStepInstruction);
  REGISTER("/info", DebuggerCommandGetThreadInfo);
  REGISTER("/context", DebuggerCommandGetContext);
  REGISTER("/fullcontext", DebuggerCommandGetFullContext);
  REGISTER("/haltall", DebuggerCommandHaltAll);
  REGISTER("/halt", DebuggerCommandHalt);
  REGISTER("/continueall", DebuggerCommandContinueAll);
  REGISTER("/continue", DebuggerCommandContinue);
  REGISTER("/suspend", DebuggerCommandSuspend);
  REGISTER("/resume", DebuggerCommandResume);
  auto step_function = std::make_shared<DebuggerCommandStepFunction>();
  commands_["/stepf"] = step_function;
  commands_["/stepfun"] = step_function;

  REGISTER("altaddr", CommandAltAddr);
  REGISTER("break", CommandBreak);
  REGISTER("bye", CommandBye);
  REGISTER("continue", CommandContinue);
  REGISTER("debugoptions", CommandDebugOptions);
  REGISTER("debugger", CommandDebugger);
  REGISTER("rm", CommandDelete);
  REGISTER("ls", CommandDirList);

#undef REGISTER
}

void Shell::Run() {
  std::string line;

  while (true) {
    std::cout << prompt_;
    std::getline(std::cin, line);

    boost::algorithm::trim(line);
    if (line.empty()) {
      continue;
    }

    std::vector<std::string> args;
    boost::escaped_list_separator<char> separator('\\', ' ', '\"');
    typedef boost::tokenizer<boost::escaped_list_separator<char>>
        SpaceTokenizer;
    SpaceTokenizer keyvals(line, separator);
    for (auto it = keyvals.begin(); it != keyvals.end(); ++it) {
      const std::string &token = *it;
      if (token[0] == '\"') {
        // Insert the unescaped contents of the string.
        std::string value = token.substr(1, token.size() - 1);
        boost::replace_all(value, "\\\"", "\"");
        args.push_back(value);
      } else {
        args.push_back(token);
      }
    }

    Command::Result result = ProcessCommand(args);
    if (result == Command::EXIT_REQUESTED) {
      break;
    }

    if (result == Command::UNHANDLED) {
      std::cout << "Unknown command." << std::endl;
    }
  }
}

Command::Result Shell::ProcessCommand(std::vector<std::string> &args) {
  std::string command = args.front();
  boost::algorithm::to_lower(command);
  args.erase(args.begin());

  if (command == "help" || command == "?") {
    PrintHelp(args);
    return Command::HANDLED;
  }

  auto it = commands_.find(command);
  if (it != commands_.end()) {
    Command &handler = *it->second;
    return handler(*interface_, args);
  }

  return Command::UNHANDLED;
}

void Shell::PrintHelp(std::vector<std::string> &args) const {
  if (args.empty()) {
    std::cout << "Commands:" << std::endl;

    for (auto &it : commands_) {
      std::cout << it.first << std::endl;
    }
    return;
  }

  std::string target = args.front();
  boost::algorithm::to_lower(target);

  if (target == "help") {
    std::cout << "[command]" << std::endl;
    std::cout << "With no argument: print all commands." << std::endl;
    std::cout << "With argument: print detailed help about `command`."
              << std::endl;
    return;
  }

  auto it = commands_.find(target);
  if (it != commands_.end()) {
    Command &handler = *it->second;
    handler.PrintUsage();
    return;
  }

  std::cout << "Unknown command '" << target << "'" << std::endl;
}
