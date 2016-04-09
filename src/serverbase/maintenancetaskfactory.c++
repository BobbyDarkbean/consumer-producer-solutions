#include "maintenancetask.h"
#include "maintenancetaskfactory.h"

namespace Cps {

MaintenanceTaskFactory::MaintenanceTaskFactory(Intercom *intercom)
    : IConnectionTaskFactory(),
      icom(intercom)
{
}

Intercom *MaintenanceTaskFactory::intercom() const
{ return icom; }

MaintenanceTaskFactory::~MaintenanceTaskFactory()
{
}

StopServerTaskFactory::StopServerTaskFactory(Intercom *intercom)
    : MaintenanceTaskFactory(intercom)
{
}

ConnectionTask *StopServerTaskFactory::create() const
{
    return new StopServerTask(intercom());
}

StopServerTaskFactory::~StopServerTaskFactory()
{
}

} // namespace Cps
