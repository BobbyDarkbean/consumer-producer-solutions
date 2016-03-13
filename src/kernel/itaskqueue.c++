#include "itaskqueue.h"

namespace Cps {

ITaskQueue::ITaskQueue()
{
    // no-op
}

void ITaskQueue::push(ITask *)
{
    // no-op
}

ITask *ITaskQueue::pop()
{
    return nullptr;
}

ITaskQueue::~ITaskQueue()
{
    // no-op
}

} // namespace Cps
