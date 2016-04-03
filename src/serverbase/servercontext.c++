#include <memory>
#include "ireplyencoder.h"
#include "irequestdecoder.h"
#include "isocketcontroller.h"
#include "itaskqueue.h"

#include "servercontext.h"

namespace Cps {

struct ServerContextImplementation
{
    std::unique_ptr<ITaskQueue> queue;
    std::unique_ptr<ISocketController> controller;
    std::unique_ptr<IRequestDecoder> decoder;
    std::unique_ptr<IReplyEncoder> encoder;
};

ServerContext::ServerContext()
    : m(new ServerContextImplementation)
{
}

ITaskQueue *ServerContext::queue() const
{ return m->queue.get(); }

void ServerContext::setQueue(ITaskQueue *queue)
{ m->queue.reset(queue); }

ISocketController *ServerContext::controller() const
{ return m->controller.get(); }

void ServerContext::setController(ISocketController *controller)
{ m->controller.reset(controller); }

IRequestDecoder *ServerContext::decoder() const
{ return m->decoder.get(); }

void ServerContext::setDecoder(IRequestDecoder *decoder)
{ m->decoder.reset(decoder); }

IReplyEncoder *ServerContext::encoder() const
{ return m->encoder.get(); }

void ServerContext::setEncoder(IReplyEncoder *encoder)
{ m->encoder.reset(encoder); }

ServerContext::~ServerContext()
{
    delete m;
}

} // namespace Cps
