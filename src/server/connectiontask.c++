#include "connectiontask.h"

namespace Cps {

struct ConnectionTaskImplementation
{
    ConnectionTaskImplementation();

    RequestData *data;
};

ConnectionTaskImplementation::ConnectionTaskImplementation()
    : data(nullptr)
{
    // no-op
}

ConnectionTask::ConnectionTask()
    : ITask(),
      m_ConnectionTask_impl(new ConnectionTaskImplementation)
{
    // no-op
}

RequestData *ConnectionTask::data() const
{
    M_UNIQUE(ConnectionTask);
    return m->data;
}

void ConnectionTask::setData(RequestData *data)
{
    M_UNIQUE(ConnectionTask);
    m->data = data;
}

void ConnectionTask::run()
{
    ITask::run();
}

ConnectionTask::~ConnectionTask()
{
    delete m_ConnectionTask_impl;
}

} // namespace Cps
