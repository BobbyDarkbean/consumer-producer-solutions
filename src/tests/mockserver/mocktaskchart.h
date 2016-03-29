#ifndef _MockTaskChart_h_
#define _MockTaskChart_h_

#include "iconnectiontaskchart.h"
#include "cps_mockserver_shared.h"

namespace Cps {

class MockLogicFacade;

struct MockTaskChartImplementation;
class CPS_MOCKSERVER_SHARED MockTaskChart : public IConnectionTaskChart
{
public:
    MockTaskChart();

    void imbue(ConnectionTaskCreator *);

    MockLogicFacade *logicFacade() const;
    void setLogicFacade(MockLogicFacade *);

    ~MockTaskChart();

private:
    DECLARE_INDIVIDUAL(MockTaskChart)
    DECLARE_UNIQUE_IMPLEMENTATION(MockTaskChart)
};

} // namespace Cps

#endif // _MockTaskChart_h_
