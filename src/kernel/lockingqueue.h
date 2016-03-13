#ifndef _LockingQueue_h_
#define _LockingQueue_h_

#include "itaskqueue.h"

namespace Cps {

struct LockingQueueImplementation;
class CPS_KERNEL_SHARED LockingQueue : public ITaskQueue
{
public:
    LockingQueue();

    void push(ITask *);
    ITask *pop();

    ~LockingQueue();

private:
    DECLARE_INDIVIDUAL(LockingQueue)
    DECLARE_IMPLEMENTATION(LockingQueue)
};

} // namespace Cps

#endif // _LockingQueue_h_
