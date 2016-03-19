#include <list>
#include <memory>

#include "connectiondata.h"
#include "ireplyencoder.h"
#include "irequestdecoder.h"
#include "isocketcontroller.h"
#include "itaskqueue.h"
#include "requestdata.h"

#include "taskscheduler.h"

namespace Cps {

struct TaskSchedulerImplementation
{
    TaskSchedulerImplementation();

    ISocketController *socketController;
    IRequestDecoder *requestDecoder;
    IReplyEncoder *replyEncoder;

    ConnectionTaskCreator creator;
};

TaskSchedulerImplementation::TaskSchedulerImplementation()
    : socketController(nullptr),
      requestDecoder(nullptr),
      replyEncoder(nullptr),
      creator()
{
    // no-op
}

TaskScheduler::TaskScheduler()
    : Producer(),
      m_TaskScheduler_impl(new TaskSchedulerImplementation)
{
    // no-op
}

void TaskScheduler::run()
{
    std::list<std::unique_ptr<RequestData>> requests;

    while (true) {
        // dealing with the finished requests
        for (auto i = requests.begin(); i != requests.end(); ) {
            if ((*i)->state.load() == RequestState_ReplyReady) {
                ConnectionData data = replyEncoder()->encode(i->get());
                socketController()->write(data);
                i = requests.erase(i);
            } else {
                ++i;
            }
        }

        if (!socketController()->isReadyToRead())
            continue;

        // request decoding and data creation
        ConnectionData data = socketController()->read();
        std::unique_ptr<RequestData> request(requestDecoder()->decode(data));
        if (!request)
            continue;

        // task creation
        ConnectionTask *task = creator()->createTask(request->type);
        task->setData(request.get());

        // pushing task to queue
        queue()->push(task);
        requests.push_back(std::move(request)); // request stored in local list
    }
}

ConnectionTaskCreator *TaskScheduler::creator() const
{
    M_UNIQUE(TaskScheduler);
    return &m->creator;
}

ISocketController *TaskScheduler::socketController() const
{
    M_UNIQUE(TaskScheduler);
    return m->socketController;
}

void TaskScheduler::setSocketController(ISocketController *controller)
{
    M_UNIQUE(TaskScheduler);
    m->socketController = controller;
}

IRequestDecoder *TaskScheduler::requestDecoder() const
{
    M_UNIQUE(TaskScheduler);
    return m->requestDecoder;
}

void TaskScheduler::setRequestDecoder(IRequestDecoder *decoder)
{
    M_UNIQUE(TaskScheduler);
    m->requestDecoder = decoder;
}

IReplyEncoder *TaskScheduler::replyEncoder() const
{
    M_UNIQUE(TaskScheduler);
    return m->replyEncoder;
}

void TaskScheduler::setReplyEncoder(IReplyEncoder *encoder)
{
    M_UNIQUE(TaskScheduler);
    m->replyEncoder = encoder;
}

TaskScheduler::~TaskScheduler()
{
    delete m_TaskScheduler_impl;
}

} // namespace Cps
