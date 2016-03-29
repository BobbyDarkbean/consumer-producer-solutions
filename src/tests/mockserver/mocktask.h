#ifndef _MockTask_h_
#define _MockTask_h_

#include "connectiontask.h"
#include "cps_kernel_global.h"

namespace Cps {

class MockLogicFacade;

class MockTask : public ConnectionTask
{
public:
    explicit MockTask(MockLogicFacade *);

    MockLogicFacade *logicFacade() const;
    void run();

    ~MockTask();

private:
    DECLARE_INDIVIDUAL(MockTask)
    MockLogicFacade *l;
};

class MockTask1 : public MockTask
{
public:
    explicit MockTask1(MockLogicFacade *);
    int type() const;
    ~MockTask1();

private:
    DECLARE_INDIVIDUAL(MockTask1)
};

class MockTask2 : public MockTask
{
public:
    explicit MockTask2(MockLogicFacade *);
    int type() const;
    ~MockTask2();

private:
    DECLARE_INDIVIDUAL(MockTask2)
};

} // namespace Cps

#endif // _MockTask_h_
