#include "intercom.h"
#include "requestdata.h"

#include "maintenancetask.h"

namespace Cps {

MaintenanceTask::MaintenanceTask(Intercom *intercom)
    : ConnectionTask(),
      icom(intercom)
{
}

Intercom *MaintenanceTask::intercom() const
{ return icom; }

MaintenanceTask::~MaintenanceTask()
{
}

StopServerTask::StopServerTask(Intercom *intercom)
    : MaintenanceTask(intercom)
{
}

int StopServerTask::type() const
{ return MaintenanceTask_StopServer; }

void StopServerTask::run()
{
    intercom()->stopServer();
    data()->state.store(RequestState_ReplyReady);
}

StopServerTask::~StopServerTask()
{
}

} // namespace Cps
