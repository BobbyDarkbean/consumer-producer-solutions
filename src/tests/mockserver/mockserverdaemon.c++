#include "lockingqueue.h"

#include "servercontext.h"

#include "mocktaskchart.h"
#include "mocksocketcontroller.h"
#include "mockrequestdecoder.h"
#include "mockreplyencoder.h"
#include "mocklogicfacade.h"

#include "mockserverdaemon.h"

namespace Cps {

struct MockServerDaemonImplementation
{
    ServerContext context;
    MockTaskChart chart;

    MockLogicFacade logicFacade;
};

MockServerDaemon::MockServerDaemon()
    : m_MockServerDaemon_impl(new MockServerDaemonImplementation)
{
    M_UNIQUE(MockServerDaemon);
#ifdef CPS_MOCKSERVER_TEST_RUN_DURATION
    m->logicFacade.setTestDuration(CPS_MOCKSERVER_TEST_RUN_DURATION);
#endif
    m->context.setQueue(new LockingQueue);
    m->context.setController(new MockSocketController(&m->logicFacade));
    m->context.setDecoder(new MockRequestDecoder);
    m->context.setEncoder(new MockReplyEncoder);
#ifdef CPS_MOCKSERVER_CONSUMER_THREADS
    m->context.setConsumerThreads(CPS_MOCKSERVER_CONSUMER_THREADS);
#endif
#ifdef CPS_MOCKSERVER_CONSUMER_WAIT_INTERVAL
    m->context.setConsumerWaitMsecs(CPS_MOCKSERVER_CONSUMER_WAIT_INTERVAL);
#endif

    m->chart.setLogicFacade(&m->logicFacade);
}

MockServerDaemon::~MockServerDaemon()
{
    delete m_MockServerDaemon_impl;
}

MockLogicFacade *MockServerDaemon::logicFacade() const
{
    M_UNIQUE(MockServerDaemon);
    return &m->logicFacade;
}

ServerContext *MockServerDaemon::context() const
{
    M_UNIQUE(MockServerDaemon);
    return &m->context;
}

IConnectionTaskChart *MockServerDaemon::chart() const
{
    M_UNIQUE(MockServerDaemon);
    return &m->chart;
}

} // namespace Cps
