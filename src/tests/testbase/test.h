#ifndef _Test_h_
#define _Test_h_

#include "irunnable.h"
#include "cps_testbase_shared.h"

namespace Cps {

class Tester;

struct TestImplementation;
class CPS_TESTBASE_SHARED Test : public IRunnable
{
public:
    Test();

    Tester *tester() const;
    void setTester(Tester *);

    ~Test();

private:
    DECLARE_INDIVIDUAL(Test)
    DECLARE_UNIQUE_IMPLEMENTATION(Test)
};

} // namespace Cps

#endif // _Test_h_
