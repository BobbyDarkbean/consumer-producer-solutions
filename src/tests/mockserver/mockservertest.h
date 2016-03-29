#ifndef _MockServerTest_h_
#define _MockServerTest_h_

#include "test.h"
#include "cps_mockserver_shared.h"

namespace Cps {

class CPS_MOCKSERVER_SHARED MockServerTest : public Test
{
public:
    MockServerTest();
    void run();
    ~MockServerTest();

private:
    DECLARE_INDIVIDUAL(MockServerTest)
};

} // namespace Cps

#endif // _MockServerTest_h_
