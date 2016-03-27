#ifndef _RequestData_h_
#define _RequestData_h_

#include <string>
#include <atomic>
#include "cps_server_shared.h"

namespace Cps {

enum RequestState
{
    RequestState_Undefined,
    RequestState_Initialized,
    RequestState_InProcess,
    RequestState_ReplyReady
};

struct CPS_SERVER_SHARED RequestData
{
    RequestData();

    int socketId;
    int type;
    std::string request;
    std::string reply;
    std::atomic<int> state;

private:
    DECLARE_INDIVIDUAL(RequestData)
};

RequestData::RequestData()
    : socketId(-1),
      type(-1),
      request(),
      reply(),
      state(RequestState_Undefined)
{
}

} // namespace Cps

#endif // _RequestData_h_
