#ifndef _TaskScheduler_h_
#define _TaskScheduler_h_

#include "producer.h"
#include "connectiontaskcreator.h"
#include "cps_serverbase_shared.h"

namespace Cps {

class Intercom;
class IReplyEncoder;
class IRequestDecoder;
class ISocketController;

struct TaskSchedulerImplementation;
class CPS_SERVERBASE_SHARED TaskScheduler : public Producer
{
public:
    TaskScheduler();

    void initIntercom(Intercom *intercom);

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
