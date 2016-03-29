#include "connectiontaskcreator.h"
#include "mocktaskfactory.h"

#include "mocktaskchart.h"

namespace Cps {

struct MockTaskChartImplementation
{
    MockTaskChartImplementation();

    MockLogicFacade *logicFacade;
};

MockTaskChartImplementation::MockTaskChartImplementation()
    : logicFacade(nullptr)
{
}

MockTaskChart::MockTaskChart()
    : IConnectionTaskChart(),
      m_MockTaskChart_impl(new MockTaskChartImplementation)
{
}

void MockTaskChart::imbue(ConnectionTaskCreator *creator)
{
    creator->insertFactory(1, new MockTaskFactory1(logicFacade()));
    creator->insertFactory(2, new MockTaskFactory2(logicFacade()));
}

MockLogicFacade *MockTaskChart::logicFacade() const
{
    M_UNIQUE(MockTaskChart);
    return m->logicFacade;
}

void MockTaskChart::setLogicFacade(MockLogicFacade *logicFacade)
{
    M_UNIQUE(MockTaskChart);
    m->logicFacade = logicFacade;
}

MockTaskChart::~MockTaskChart()
{
    delete m_MockTaskChart_impl;
}

} // namespace Cps
