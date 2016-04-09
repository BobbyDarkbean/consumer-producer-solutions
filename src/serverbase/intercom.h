#ifndef _Intercom_h_
#define _Intercom_h_

#include <atomic>
#include "cps_server_shared.h"

namespace Cps {

enum ServerState
{
    ServerState_Initial,
    ServerState_Ready,
    ServerState_Running,
    ServerState_Stopping,
    ServerState_Stopped
};

struct IntercomImplementation;
class CPS_SERVER_SHARED Intercom
{
public:
    Intercom();

    void init(std::atomic<int> *serverState);

    int recentServerState() const;
    void stopServer();

    ~Intercom();

private:
    DECLARE_INDIVIDUAL(Intercom)
    DECLARE_IMPLEMENTATION(Intercom)
};

} // namespace Cps

#endif // _Intercom_h_
