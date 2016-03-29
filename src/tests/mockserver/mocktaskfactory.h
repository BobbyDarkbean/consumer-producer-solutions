#ifndef _MockTaskFactory_h_
#define _MockTaskFactory_h_

#include "iconnectiontaskfactory.h"
#include "cps_kernel_global.h"

namespace Cps {

class MockLogicFacade;

class MockTaskFactory : public IConnectionTaskFactory
{
public:
    explicit MockTaskFactory(MockLogicFacade *);
    MockLogicFacade *logicFacade() const;
    ~MockTaskFactory();

private:
    DECLARE_INDIVIDUAL(MockTaskFactory)
    MockLogicFacade *l;
};

class MockTaskFactory1 : public MockTaskFactory
{
public:
    explicit MockTaskFactory1(MockLogicFacade *);
    ConnectionTask *create() const;
    ~MockTaskFactory1();

private:
    DECLARE_INDIVIDUAL(MockTaskFactory1)
};

class MockTaskFactory2 : public MockTaskFactory
{
public:
    explicit MockTaskFactory2(MockLogicFacade *);
    ConnectionTask *create() const;
    ~MockTaskFactory2();

private:
    DECLARE_INDIVIDUAL(MockTaskFactory2)
};

} // namespace Cps

#endif // _MockTaskFactory_h_
