#ifndef _WorkLoop_h_
#define _WorkLoop_h_

#include "cps_serverbase_shared.h"

namespace Cps {

class ServerContext;
class IConnectionTaskChart;

struct WorkLoopImplementation;
class CPS_SERVERBASE_SHARED WorkLoop
{
public:
    WorkLoop();

    int consumerThreads() const;
    void setConsumerThreads(int);

    ServerContext *context() const;
    void setContext(ServerContext *);

    IConnectionTaskChart *chart() const;
    void setChart(IConnectionTaskChart *);

    int execute();

    ~WorkLoop();

private:
    DECLARE_INDIVIDUAL(WorkLoop)
    DECLARE_IMPLEMENTATION(WorkLoop)
};

} // namespace Cps

#endif // _WorkLoop_h_
