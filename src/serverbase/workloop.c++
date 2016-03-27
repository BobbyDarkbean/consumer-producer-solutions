#include <memory>
#include <thread>
#include <vector>

#include "iconnectiontaskchart.h"
#include "taskscheduler.h"
#include "taskworker.h"

#include "workloop.h"

namespace Cps {

const int DefaultConsumerThreads = 4;

struct WorkLoopImplementation
{
    WorkLoopImplementation();

    int consumerThreads;
    ITaskQueue *queue;
    IConnectionTaskChart *chart;
};

WorkLoopImplementation::WorkLoopImplementation()
    : consumerThreads(DefaultConsumerThreads),
      queue(nullptr),
      chart(nullptr)
{
}

WorkLoop::WorkLoop()
    : m(new WorkLoopImplementation)
{
}

int WorkLoop::consumerThreads() const
{ return m->consumerThreads; }

void WorkLoop::setConsumerThreads(int threads)
{ m->consumerThreads = threads; }

ITaskQueue *WorkLoop::queue() const
{ return m->queue; }

void WorkLoop::setQueue(ITaskQueue *queue)
{ m->queue = queue; }

IConnectionTaskChart *WorkLoop::chart() const
{ return m->chart; }

void WorkLoop::setChart(IConnectionTaskChart *chart)
{ m->chart = chart; }

int WorkLoop::execute()
{
    TaskScheduler scheduler;
    scheduler.setQueue(m->queue);
    m->chart->imbue(scheduler.creator());

    std::vector<std::unique_ptr<TaskWorker>> workers;
    std::vector<std::thread> threads;

    for (int i = 0; i < m->consumerThreads; ++i) {
        TaskWorker *worker = new TaskWorker;
        worker->setQueue(m->queue);

        workers.emplace_back(worker);
        threads.push_back(std::thread(TaskWorker::run, worker));
    }

    scheduler.run();

    for (std::thread &th: threads) {
        th.join();
    }

    return 0;
}

WorkLoop::~WorkLoop()
{
    delete m;
}

} // namespace Cps
