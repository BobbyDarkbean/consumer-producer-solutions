#include <memory>
#include <thread>
#include <vector>

#include "iconnectiontaskchart.h"
#include "servercontext.h"
#include "taskscheduler.h"
#include "taskworker.h"

#include "workloop.h"

namespace Cps {

const int DefaultConsumerThreads = 4;

struct WorkLoopImplementation
{
    WorkLoopImplementation();

    void provideContext(TaskScheduler *);

    int consumerThreads;
    ServerContext *context;
    IConnectionTaskChart *chart;
};

WorkLoopImplementation::WorkLoopImplementation()
    : consumerThreads(DefaultConsumerThreads),
      context(nullptr),
      chart(nullptr)
{
}

void WorkLoopImplementation::provideContext(TaskScheduler *scheduler)
{
    scheduler->setQueue(context->queue());
    scheduler->setSocketController(context->controller());
    scheduler->setRequestDecoder(context->decoder());
    scheduler->setReplyEncoder(context->encoder());
}

WorkLoop::WorkLoop()
    : m(new WorkLoopImplementation)
{
}

int WorkLoop::consumerThreads() const
{ return m->consumerThreads; }

void WorkLoop::setConsumerThreads(int threads)
{ m->consumerThreads = threads; }

ServerContext *WorkLoop::context() const
{ return m->context; }

void WorkLoop::setContext(ServerContext *context)
{ m->context = context; }

IConnectionTaskChart *WorkLoop::chart() const
{ return m->chart; }

void WorkLoop::setChart(IConnectionTaskChart *chart)
{ m->chart = chart; }

int WorkLoop::execute()
{
    TaskScheduler scheduler;
    m->provideContext(&scheduler);
    m->chart->imbue(scheduler.creator());

    std::vector<std::unique_ptr<TaskWorker>> workers;
    std::vector<std::thread> threads;

    for (int i = 0; i < m->consumerThreads; ++i) {
        TaskWorker *worker = new TaskWorker;
        worker->setQueue(m->context->queue());

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
