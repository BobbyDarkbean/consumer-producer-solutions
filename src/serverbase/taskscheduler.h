#ifndef _TaskScheduler_h_
#define _TaskScheduler_h_

#include "producer.h"
#include "connectiontaskcreator.h"
#include "cps_server_shared.h"

namespace Cps {

class IReplyEncoder;
class IRequestDecoder;
class ISocketController;

struct TaskSchedulerImplementation;
class CPS_SERVER_SHARED TaskScheduler : public Producer
{
public:
    TaskScheduler();

    void run();
    ConnectionTaskCreator *creator() const;

    ISocketController *socketController() const;
    void setSocketController(ISocketController *);

    IRequestDecoder *requestDecoder() const;
    void setRequestDecoder(IRequestDecoder *);

    IReplyEncoder *replyEncoder() const;
    void setReplyEncoder(IReplyEncoder *);

    ~TaskScheduler();

private:
    DECLARE_INDIVIDUAL(TaskScheduler)
    DECLARE_UNIQUE_IMPLEMENTATION(TaskScheduler)
};

} // namespace Cps

#endif // _TaskScheduler_h_
