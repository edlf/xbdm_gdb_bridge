#include "handler_commands.h"

#include <fstream>

#include "handler_loader/dxt_library.h"
#include "handler_loader/handler_loader.h"
#include "handler_loader/handler_requests.h"
#include "xbox/debugger/xbdm_debugger.h"

Command::Result HandlerCommandLoadBootstrap::operator()(
    XBOXInterface &interface, const std::vector<std::string> &) {
  auto debugger = interface.Debugger();
  if (!debugger) {
    std::cout << "Debugger not attached." << std::endl;
    return HANDLED;
  }

  if (!debugger->HaltAll()) {
    std::cout << "Failed to halt target." << std::endl;
  }

  bool successful = HandlerLoader::Bootstrap(interface);
  if (!successful) {
    std::cout << "Failed to inject handler loader. XBDM handlers will not work."
              << std::endl;
  }

cleanup:
  if (!debugger->ContinueAll()) {
    std::cout << "Failed to resume target." << std::endl;
  }

  if (!debugger->Go()) {
    std::cout << "Failed to go." << std::endl;
  }

  return HANDLED;
}

Command::Result HandlerCommandHello::operator()(
    XBOXInterface &interface, const std::vector<std::string> &) {
  auto request = std::make_shared<HandlerInvokeSimple>("ddxt!hello");
  interface.SendCommandSync(request);
  if (!request->IsOK()) {
    std::cout << *request << std::endl;
    return HANDLED;
  }

  std::cout << *request << std::endl;
  return HANDLED;
}

Command::Result HandlerCommandInvokeSimple::operator()(
    XBOXInterface &interface, const std::vector<std::string> &args) {
  ArgParser parser(args);
  std::string command;
  if (!parser.Parse(0, command)) {
    std::cout << "Missing required `processor!command` argument." << std::endl;
    return HANDLED;
  }
  std::string command_line_args;
  parser.Parse(1, command_line_args);

  auto request =
      std::make_shared<HandlerInvokeSimple>(command, command_line_args);
  interface.SendCommandSync(request);
  if (!request->IsOK()) {
    std::cout << *request << std::endl;
    return HANDLED;
  }

  std::cout << *request << std::endl;

  return HANDLED;
}

Command::Result HandlerCommandLoad::operator()(
    XBOXInterface &interface, const std::vector<std::string> &args) {
  ArgParser parser(args);
  std::string path;
  if (!parser.Parse(0, path)) {
    std::cout << "Missing required <dll_path> argument." << std::endl;
    return HANDLED;
  }

  DXTLibrary lib(path);
  if (!lib.Parse()) {
    std::cout << "Failed to load DXT DLL from '" << path << "'" << std::endl;
    return HANDLED;
  }

  uint32_t address = 0;
  {
    auto request = std::make_shared<HandlerDDXTReserve>(lib.GetImageSize());
    interface.SendCommandSync(request);
    if (!request->IsOK()) {
      std::cout << *request << std::endl;
      return HANDLED;
    }
    std::cout << *request << std::endl;
  }

  lib.Relocate(address);

  {
    auto request = std::make_shared<HandlerDDXTLoad>(
        address, lib.GetImage(), lib.GetTLSInitializers(), lib.GetEntrypoint());
    interface.SendCommandSync(request);
    if (!request->IsOK()) {
      // TODO: Free the remote allocated buffer.
      std::cout << *request << std::endl;
      return HANDLED;
    }
    std::cout << *request << std::endl;
  }

  return HANDLED;
}
