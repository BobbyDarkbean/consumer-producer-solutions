#ifndef _ServerContext_h_
#define _ServerContext_h_

#include "cps_server_shared.h"

namespace Cps {

class IReplyEncoder;
class IRequestDecoder;
class ISocketController;
class ITaskQueue;

struct ServerContextImplementation;
class CPS_SERVER_SHARED ServerContext
{
public:
    ServerContext();

    ITaskQueue *queue() const;
    void setQueue(ITaskQueue *);

    ISocketController *controller() const;
    void setController(ISocketController *);

    IRequestDecoder *decoder() const;
    void setDecoder(IRequestDecoder *);

    IReplyEncoder *encoder() const;
    void setEncoder(IReplyEncoder *);

    ~ServerContext();

private:
    DECLARE_INDIVIDUAL(ServerContext)
    DECLARE_IMPLEMENTATION(ServerContext)
};

} // namespace Cps

#endif // _ServerContext_h_
