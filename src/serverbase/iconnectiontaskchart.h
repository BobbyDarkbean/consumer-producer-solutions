#ifndef _IConnectionTaskChart_h_
#define _IConnectionTaskChart_h_

#include "cps_serverbase_shared.h"

namespace Cps {

class ConnectionTaskCreator;

class CPS_SERVERBASE_SHARED IConnectionTaskChart
{
public:
    IConnectionTaskChart();
    virtual void imbue(ConnectionTaskCreator *) = 0;
    virtual ~IConnectionTaskChart() = 0;

private:
    DECLARE_INDIVIDUAL(IConnectionTaskChart)
};

} // namespace Cps

#endif // _IConnectionTaskChart_h_
