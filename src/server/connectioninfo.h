#ifndef _ConnectionInfo_h_
#define _ConnectionInfo_h_

#include <string>
#include <atomic>

namespace Cps {

enum ConnectionState
{
    ConnState_Undefined,
    ConnState_Initialized,
    ConnState_InProcess,
    ConnState_ReplyReady
};

struct ConnectionInfo
{
    ConnectionInfo();

    int socketId;
    std::string request;
    std::string reply;
    std::atomic<int> state;
};

ConnectionInfo::ConnectionInfo()
    : socketId(-1),
      request(),
      reply(),
      state(ConnState_Undefined)
{
    // no-op
}

} // namespace Cps

#endif // _ConnectionInfo_h_
