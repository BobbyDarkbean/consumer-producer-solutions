#include "test.h"

namespace Cps {

struct TestImplementation
{
    TestImplementation();

    Tester *tester;
};

TestImplementation::TestImplementation()
    : tester(0)
{
}

Test::Test()
    : IRunnable(),
      m_Test_impl(new TestImplementation)
{
}

Tester *Test::tester() const
{
    M_UNIQUE(Test);
    return m->tester;
}

void Test::setTester(Tester *tester)
{
    M_UNIQUE(Test);
    m->tester = tester;
}

Test::~Test()
{
    delete m_Test_impl;
}

} // namespace Cps
