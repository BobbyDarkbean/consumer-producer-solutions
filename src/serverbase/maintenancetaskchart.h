#ifndef _MaintenanceTaskChart_h_
#define _MaintenanceTaskChart_h_

#include "iconnectiontaskchart.h"

namespace Cps {

class Intercom;

struct MaintenanceTaskChartImplementation;
class MaintenanceTaskChart : public IConnectionTaskChart
{
public:
    MaintenanceTaskChart();

    void imbue(ConnectionTaskCreator *);

    Intercom *intercom() const;
    void setIntercom(Intercom *);

    ~MaintenanceTaskChart();

private:
    DECLARE_INDIVIDUAL(MaintenanceTaskChart)
    DECLARE_UNIQUE_IMPLEMENTATION(MaintenanceTaskChart)
};

} // namespace Cps

#endif // _MaintenanceTaskChart_h_
