#include <memory>
#include <thread>
#include <vector>

#include "iconnectiontaskchart.h"
#include "intercom.h"
#include "maintenancetaskchart.h"
#include "servercontext.h"
#include "taskscheduler.h"
#include "taskworker.h"

#include "workloop.h"

namespace Cps {

struct WorkLoopImplementation
{
    WorkLoopImplementation();

    void provideContext(TaskScheduler *);

    ServerContext *context;
    IConnectionTaskChart *chart;
};

WorkLoopImplementation::WorkLoopImplementation()
    : context(nullptr),
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

    Intercom intercom;
    scheduler.initIntercom(&intercom);

    MaintenanceTaskChart maintenanceChart;
    maintenanceChart.setIntercom(&intercom);
    maintenanceChart.imbue(scheduler.creator());

    std::vector<std::unique_ptr<TaskWorker>> workers;
    std::vector<std::thread> threads;

    for (int i = 0; i < m->context->consumerThreads(); ++i) {
        TaskWorker *worker = new TaskWorker;
        worker->setQueue(m->context->queue());
        worker->setMsecsToWait(m->context->consumerWaitMsecs());
        worker->setIntercom(&intercom);

        workers.emplace_back(worker);
        threads.push_back(std::thread(&TaskWorker::run, worker));
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
