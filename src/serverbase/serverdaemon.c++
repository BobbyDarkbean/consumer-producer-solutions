#include "workloop.h"
#include "serverdaemon.h"

namespace Cps {

ServerDaemon::ServerDaemon()
{
}

ServerDaemon::~ServerDaemon()
{
}

int ServerDaemon::operator()()
{
    WorkLoop loop;
    loop.setChart(chart());
    loop.setContext(context());
    return loop.execute();
}

} // namespace Cps
