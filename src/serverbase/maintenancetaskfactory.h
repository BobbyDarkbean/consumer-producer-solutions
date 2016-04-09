#ifndef _MaintenanceTaskFactory_h
#define _MaintenanceTaskFactory_h

#include "iconnectiontaskfactory.h"

namespace Cps {

class Intercom;

class MaintenanceTaskFactory : public IConnectionTaskFactory
{
public:
    explicit MaintenanceTaskFactory(Intercom *intercom);
    Intercom *intercom() const;
    ~MaintenanceTaskFactory();

private:
    DECLARE_INDIVIDUAL(MaintenanceTaskFactory)
    Intercom *icom;
};

class StopServerTaskFactory : public MaintenanceTaskFactory
{
public:
    explicit StopServerTaskFactory(Intercom *intercom);
    ConnectionTask *create() const;
    ~StopServerTaskFactory();

private:
    DECLARE_INDIVIDUAL(StopServerTaskFactory)
};

} // namespace Cps

#endif // _MaintenanceTaskFactory_h
