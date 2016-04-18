#ifndef _MockServerDaemon_h_
#define _MockServerDaemon_h_

#include "serverdaemon.h"
#include "cps_mockserver_shared.h"

namespace Cps {

class MockLogicFacade;

struct MockServerDaemonImplementation;
class CPS_MOCKSERVER_SHARED MockServerDaemon : public ServerDaemon
{
public:
    MockServerDaemon();
    ~MockServerDaemon();

    MockLogicFacade *logicFacade() const;

    ServerContext *context() const;
    IConnectionTaskChart *chart() const;

private:
    DECLARE_INDIVIDUAL(MockServerDaemon)
    DECLARE_UNIQUE_IMPLEMENTATION(MockServerDaemon)
};

} // namespace Cps

#endif // _MockServerDaemon_h_
