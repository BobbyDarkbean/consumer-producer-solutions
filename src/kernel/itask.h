#ifndef _ITask_h_
#define _ITask_h_

#include "irunnable.h"

namespace Cps {

class CPS_KERNEL_SHARED ITask : public IRunnable
{
public:
    ITask();
    void run() = 0;
    ~ITask() = 0;

private:
    DECLARE_INDIVIDUAL(ITask)
};

} // namespace Cps

#endif // _ITask_h_
