#ifndef _TaskWorker_h_
#define _TaskWorker_h_

#include "consumer.h"
#include "cps_server_shared.h"

namespace Cps {

class Intercom;

struct TaskWorkerImplementation;
class CPS_SERVER_SHARED TaskWorker : public Consumer
{
public:
    TaskWorker();

    Intercom *intercom() const;
    void setIntercom(Intercom *);

    void run();

    ~TaskWorker();

private:
    DECLARE_INDIVIDUAL(TaskWorker)
    DECLARE_UNIQUE_IMPLEMENTATION(TaskWorker)
};

} // namespace Cps

#endif // _TaskWorker_h_
