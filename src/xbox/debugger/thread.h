#ifndef XBDM_GDB_BRIDGE_SRC_XBOX_DEBUGGER_THREAD_H_
#define XBDM_GDB_BRIDGE_SRC_XBOX_DEBUGGER_THREAD_H_

#include <cinttypes>
#include <memory>
#include <optional>

#include "rdcp/rdcp_response_processors.h"
#include "rdcp/thread_context.h"
#include "rdcp/xbdm_stop_reasons.h"
#include "xbox/xbox_interface.h"

struct Thread {
  static constexpr uint32_t kTrapFlag = 0x100;

  Thread(int thread_id) : thread_id(thread_id) {}

  bool FetchInfoSync(XBOXInterface &interface);
  bool FetchContextSync(XBOXInterface &interface);
  bool FetchFloatContextSync(XBOXInterface &interface);
  bool FetchStopReasonSync(XBOXInterface &interface);

  bool Halt(XBOXInterface &interface);
  bool Continue(XBOXInterface &interface, bool break_on_exceptions = true);
  bool Suspend(XBOXInterface &interface);
  bool Resume(XBOXInterface &interface);

 private:
  void Parse(const RDCPMapResponse &parsed) {
    suspend_count = parsed.GetDWORD("suspend");
    priority = parsed.GetDWORD("priority");
    tls_base = parsed.GetDWORD("tlsbase");
    start = parsed.GetDWORD("start");
    base = parsed.GetDWORD("base");
    limit = parsed.GetDWORD("limit");
    create_timestamp = parsed.GetQWORD("createlo", "createhi");
  }

 public:
  int thread_id;
  std::optional<int32_t> suspend_count;
  std::optional<int32_t> priority;
  std::optional<uint32_t> tls_base;
  std::optional<uint32_t> start;
  std::optional<uint32_t> base;
  std::optional<uint32_t> limit;
  std::optional<uint64_t> create_timestamp;

  std::optional<ThreadContext> context;
  std::optional<ThreadFloatContext> float_context;

  std::optional<uint32_t> last_known_address;
  std::shared_ptr<StopReasonBase_> last_stop_reason;
};

#endif  // XBDM_GDB_BRIDGE_SRC_XBOX_DEBUGGER_THREAD_H_
