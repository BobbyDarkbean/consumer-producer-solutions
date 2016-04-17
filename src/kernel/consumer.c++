#include "consumer.h"

namespace Cps {

struct ConsumerImplementation
{
    ConsumerImplementation();

    ITaskQueue *queue;
    int msecsToWait;
};

ConsumerImplementation::ConsumerImplementation()
    : queue(nullptr),
      msecsToWait(0)
{
}

Consumer::Consumer()
    : IRunnable(),
      m_Consumer_impl(new ConsumerImplementation)
{
}

ITaskQueue *Consumer::queue() const
{
    M_UNIQUE(Consumer);
    return m->queue;
}

void Consumer::setQueue(ITaskQueue *queue)
{
    M_UNIQUE(Consumer);
    m->queue = queue;
}

int Consumer::msecsToWait() const
{
    M_UNIQUE(Consumer);
    return m->msecsToWait;
}

void Consumer::setMsecsToWait(int msecs)
{
    M_UNIQUE(Consumer);
    m->msecsToWait = msecs;
}

Consumer::~Consumer()
{
    delete m_Consumer_impl;
}

} // namespace Cps
