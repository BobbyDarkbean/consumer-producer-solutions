#include <chrono>
#include <memory>
#include <thread>

#include "itask.h"
#include "itaskqueue.h"

#include "taskworker.h"

namespace Cps {

TaskWorker::TaskWorker()
    : Consumer()
{
    // no-op
}

void TaskWorker::run()
{
    std::chrono::milliseconds waitInterval(msecsToWait());

    while (true) {
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
    // no-op
}

} // namespace Cps
