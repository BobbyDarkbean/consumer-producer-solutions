#include "intercom.h"

namespace Cps {

struct IntercomImplementation
{
    IntercomImplementation();

    std::atomic<int> *serverState;
};

IntercomImplementation::IntercomImplementation()
    : serverState(nullptr)
{
}

Intercom::Intercom()
    : m(new IntercomImplementation)
{
}

void Intercom::init(std::atomic<int> *serverState)
{
    m->serverState = serverState;
    m->serverState->store(ServerState_Ready);
}

int Intercom::recentServerState() const
{
    return m->serverState->load();
}

void Intercom::stopServer()
{
    m->serverState->store(ServerState_Stopping);
}

Intercom::~Intercom()
{
    delete m;
}

} // namespace Cps
