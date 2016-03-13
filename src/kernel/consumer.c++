#include "consumer.h"

namespace Cps {

struct ConsumerImplementation
{
    ConsumerImplementation();
    ITaskQueue *queue;
};

ConsumerImplementation::ConsumerImplementation()
    : queue(nullptr)
{
    // no-op
}

Consumer::Consumer()
    : IRunnable(),
      m_Consumer_impl(new ConsumerImplementation)
{
    // no-op
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

Consumer::~Consumer()
{
    delete m_Consumer_impl;
}

} // namespace Cps
