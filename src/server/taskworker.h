#ifndef _TaskWorker_h_
#define _TaskWorker_h_

#include "consumer.h"
#include "cps_server_shared.h"

namespace Cps {

class CPS_SERVER_SHARED TaskWorker : public Consumer
{
public:
    TaskWorker();
    void run();
    ~TaskWorker();

private:
    DECLARE_INDIVIDUAL(TaskWorker)
};

} // namespace Cps

#endif // _TaskWorker_h_
