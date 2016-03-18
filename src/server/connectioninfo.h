#ifndef _ConnectionInfo_h_
#define _ConnectionInfo_h_

#include <string>
#include <atomic>

namespace Cps {

enum RequestState
{
    RequestState_Undefined,
    RequestState_Initialized,
    RequestState_InProcess,
    RequestState_Ready
};

struct ConnectionInfo
{
    int socketId;
    std::string request;
    std::string reply;
    std::atomic<int> state;
};

} // namespace Cps

#endif // _ConnectionInfo_h_
