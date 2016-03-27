#include <list>
#include <mutex>

#include "lockingqueue.h"

namespace Cps {

struct LockingQueueImplementation
{
    std::list<ITask *> tasks;
    std::mutex mutex;
};

LockingQueue::LockingQueue()
    : ITaskQueue(),
      m(new LockingQueueImplementation)
{
}

void LockingQueue::push(ITask *task)
{
    std::lock_guard<std::mutex> lock(m->mutex);
    m->tasks.push_back(task);
}

ITask *LockingQueue::pop()
{
    std::lock_guard<std::mutex> lock(m->mutex);
    if (m->tasks.empty())
        return nullptr;

    ITask *head = m->tasks.front();
    m->tasks.pop_front();
    return head;
}

LockingQueue::~LockingQueue()
{
    delete m;
}

} // namespace Cps
