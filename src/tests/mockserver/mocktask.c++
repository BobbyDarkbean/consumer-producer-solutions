#ifndef CPS_MOCKSERVER_SUPPRESS_TASK_OUTPUT
#include <iostream>
#endif

#include "requestdata.h"
#include "mocklogicfacade.h"

#include "mocktask.h"

namespace Cps {

MockTask::MockTask(MockLogicFacade *logicFacade)
    : ConnectionTask(),
      l(logicFacade)
{
}

MockLogicFacade *MockTask::logicFacade() const
{ return l; }

void MockTask::run()
{
#ifndef CPS_MOCKSERVER_SUPPRESS_TASK_OUTPUT
    std::cout << type();
#endif
    logicFacade()->increaseTaskExecutions(type());
    data()->state.store(RequestState_ReplyReady);
}

MockTask::~MockTask()
{
}

MockTask1::MockTask1(MockLogicFacade *logicFacade)
    : MockTask(logicFacade)
{
}

int MockTask1::type() const
{ return 1; }

MockTask1::~MockTask1()
{
}

MockTask2::MockTask2(MockLogicFacade *logicFacade)
    : MockTask(logicFacade)
{
}

int MockTask2::type() const
{ return 2; }

MockTask2::~MockTask2()
{
}

} // namespace Cps
