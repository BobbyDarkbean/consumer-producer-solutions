#include "connectiontaskcreator.h"
#include "maintenancetask.h"
#include "maintenancetaskfactory.h"

#include "maintenancetaskchart.h"

namespace Cps {

struct MaintenanceTaskChartImplementation
{
    MaintenanceTaskChartImplementation();

    Intercom *intercom;
};

MaintenanceTaskChartImplementation::MaintenanceTaskChartImplementation()
    : intercom(nullptr)
{
}

MaintenanceTaskChart::MaintenanceTaskChart()
    : IConnectionTaskChart(),
      m_MaintenanceTaskChart_impl(new MaintenanceTaskChartImplementation)
{
}

void MaintenanceTaskChart::imbue(ConnectionTaskCreator *creator)
{
    creator->insertFactory(MaintenanceTask_StopServer, new StopServerTaskFactory(intercom()));
}

Intercom *MaintenanceTaskChart::intercom() const
{
    M_UNIQUE(MaintenanceTaskChart);
    return m->intercom;
}

void MaintenanceTaskChart::setIntercom(Intercom *intercom)
{
    M_UNIQUE(MaintenanceTaskChart);
    m->intercom = intercom;
}

MaintenanceTaskChart::~MaintenanceTaskChart()
{
    delete m_MaintenanceTaskChart_impl;
}

} // namespace Cps
