#include <iostream>
#include <list>
#include <memory>

#include "testbase/test.h"
#include "testbase/tester.h"
#include "test_config.h"

#if TEST_MOCK_SERVER
#include "mockserver/mockservertest.h"
#endif

int main()
{
    Cps::Tester tester;
    tester.setLog(&std::cout);

    std::list<std::unique_ptr<Cps::Test>> tests;

#if TEST_MOCK_SERVER
    tests.emplace_back(new Cps::MockServerTest);
#endif

    for (auto &test: tests) {
        test->setTester(&tester);
        test->run();
    }

    return 0;
}
