#ifndef _ITaskQueue_h_
#define _ITaskQueue_h_

#include "cps_kernel_shared.h"

namespace Cps {

class ITask;

class CPS_KERNEL_SHARED ITaskQueue
{
public:
    ITaskQueue();

    virtual void push(ITask *) = 0;
    virtual ITask *pop() = 0;

    virtual ~ITaskQueue() = 0;

private:
    DECLARE_INDIVIDUAL(ITaskQueue)
};

} // namespace Cps

#endif // _ITaskQueue_h_
