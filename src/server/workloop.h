#ifndef _WorkLoop_h_
#define _WorkLoop_h_

#include "cps_server_shared.h"

namespace Cps {

class ITaskQueue;
class IConnectionTaskChart;

struct WorkLoopImplementation;
class CPS_SERVER_SHARED WorkLoop
{
public:
    WorkLoop();

    int consumerThreads() const;
    void setConsumerThreads(int);

    ITaskQueue *queue() const;
    void setQueue(ITaskQueue *);

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
