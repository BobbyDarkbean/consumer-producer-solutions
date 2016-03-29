#include "mocktask.h"
#include "mocktaskfactory.h"

namespace Cps {

MockTaskFactory::MockTaskFactory(MockLogicFacade *logicFacade)
    : IConnectionTaskFactory(),
      l(logicFacade)
{
}

MockLogicFacade *MockTaskFactory::logicFacade() const
{ return l; }

MockTaskFactory::~MockTaskFactory()
{
}

MockTaskFactory1::MockTaskFactory1(MockLogicFacade *logicFacade)
    : MockTaskFactory(logicFacade)
{
}

ConnectionTask *MockTaskFactory1::create() const
{
    return new MockTask1(logicFacade());
}

MockTaskFactory1::~MockTaskFactory1()
{
}

MockTaskFactory2::MockTaskFactory2(MockLogicFacade *logicFacade)
    : MockTaskFactory(logicFacade)
{
}

ConnectionTask *MockTaskFactory2::create() const
{
    return new MockTask2(logicFacade());
}

MockTaskFactory2::~MockTaskFactory2()
{
}

} // namespace Cps
