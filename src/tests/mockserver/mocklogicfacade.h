#ifndef _MockLogicFacade_h_
#define _MockLogicFacade_h_

#include "cps_kernel_global.h"

namespace Cps {

struct MockLogicFacadeImplementation;
class MockLogicFacade
{
public:
    MockLogicFacade();

    int totalDataCount() const;
    int rawDataCreations(int type) const;
    int taskExecutions(int type) const;
    int rawDataReadings() const;
    int rawDataWritings() const;

    void increaseRawDataCreations(int type);
    void increaseTaskExecutions(int type);
    void increaseRawDataReadings();
    void increaseRawDataWritings();

    int testDuration() const;
    void setTestDuration(int secs);

    ~MockLogicFacade();

private:
    DECLARE_INDIVIDUAL(MockLogicFacade)
    DECLARE_IMPLEMENTATION(MockLogicFacade)
};

} // namespace Cps

#endif // _MockLogicFacade_h_
