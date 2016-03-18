#include "connectioninfo.h"
#include "connectiontask.h"

namespace Cps {

struct ConnectionTaskImplementation
{
    std::shared_ptr<ConnectionInfo> info;
};

ConnectionTask::ConnectionTask()
    : ITask(),
      m_ConnectionTask_impl(new ConnectionTaskImplementation)
{
    // no-op
}

std::shared_ptr<ConnectionInfo> ConnectionTask::info() const
{
    M_UNIQUE(ConnectionTask);
    return m->info;
}

void ConnectionTask::setInfo(const std::shared_ptr<ConnectionInfo> &info)
{
    M_UNIQUE(ConnectionTask);
    m->info = info;
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
