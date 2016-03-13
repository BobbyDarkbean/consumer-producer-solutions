#include "itaskqueue.h"

namespace Cps {

ITaskQueue::ITaskQueue()
{
    // no-op
}

ITask *ITaskQueue::pop()
{
    return nullptr;
}

void ITaskQueue::push(ITask *)
{
    // no-op
}

ITaskQueue::~ITaskQueue()
{
    // no-op
}

} // namespace Cps
