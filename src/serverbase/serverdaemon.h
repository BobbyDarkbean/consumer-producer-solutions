#ifndef _ServerDaemon_h_
#define _ServerDaemon_h_

#include "cps_serverbase_shared.h"

namespace Cps {

class IConnectionTaskChart;
class ServerContext;

class CPS_SERVERBASE_SHARED ServerDaemon
{
public:
    ServerDaemon();
    virtual ~ServerDaemon() = 0;

    int operator()();

protected:
    virtual ServerContext *context() const = 0;
    virtual IConnectionTaskChart *chart() const = 0;

private:
    DECLARE_INDIVIDUAL(ServerDaemon)
};

} // namespace Cps

#endif // _ServerDaemon_h_
