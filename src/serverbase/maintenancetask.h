#ifndef _MaintenanceTask_h_
#define _MaintenanceTask_h_

#include "connectiontask.h"

namespace Cps {

enum MaintenanceTaskType
{
    MaintenanceTask_StopServer = -1
};

class Intercom;

class MaintenanceTask : public ConnectionTask
{
public:
    explicit MaintenanceTask(Intercom *);
    Intercom *intercom() const;
    ~MaintenanceTask();

private:
    DECLARE_INDIVIDUAL(MaintenanceTask)
    Intercom *icom;
};

class StopServerTask : public MaintenanceTask
{
public:
    explicit StopServerTask(Intercom *);

    int type() const;
    void run();

    ~StopServerTask();

private:
    DECLARE_INDIVIDUAL(StopServerTask)
};

} // namespace Cps

#endif // _MaintenanceTask_h_
