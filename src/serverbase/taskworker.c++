#include <chrono>
#include <memory>
#include <thread>

#include "intercom.h"
#include "itask.h"
#include "itaskqueue.h"

#include "taskworker.h"

namespace Cps {

struct TaskWorkerImplementation
{
    TaskWorkerImplementation();

    Intercom *intercom;
};

TaskWorkerImplementation::TaskWorkerImplementation()
    : intercom(nullptr)
{
}

TaskWorker::TaskWorker()
    : Consumer(),
      m_TaskWorker_impl(new TaskWorkerImplementation)
{
}

Intercom *TaskWorker::intercom() const
{
    M_UNIQUE(TaskWorker);
    return m->intercom;
}

void TaskWorker::setIntercom(Intercom *intercom)
{
    M_UNIQUE(TaskWorker);
    m->intercom = intercom;
}

void TaskWorker::run()
{
    std::chrono::milliseconds waitInterval(msecsToWait());

    while (intercom()->recentServerState() != ServerState_Stopped) {
        std::unique_ptr<ITask> task(queue()->pop());

        if (task) {
            task->run();
        } else {
            std::this_thread::sleep_for(waitInterval);
        }
    }
}

TaskWorker::~TaskWorker()
{
    delete m_TaskWorker_impl;
}

} // namespace Cps
