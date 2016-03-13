#include "producer.h"

namespace Cps {

struct ProducerImplementation
{
    ProducerImplementation();
    ITaskQueue *queue;
};

ProducerImplementation::ProducerImplementation()
    : queue(nullptr)
{
    // no-op
}

Producer::Producer()
    : IRunnable(),
      m_Producer_impl(new ProducerImplementation)
{
    // no-op
}

ITaskQueue *Producer::queue() const
{
    M_UNIQUE(Producer);
    return m->queue;
}

void Producer::setQueue(ITaskQueue *queue)
{
    M_UNIQUE(Producer);
    m->queue = queue;
}

ITaskCreator *Producer::creator() const
{
    return nullptr;
}

Producer::~Producer()
{
    delete m_Producer_impl;
}

} // namespace Cps
