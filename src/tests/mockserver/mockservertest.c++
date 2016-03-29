#include "tester.h"
#include "mocklogicfacade.h"
#include "mockserverdaemon.h"

#include "mockservertest.h"

namespace Cps {

MockServerTest::MockServerTest()
    : Test()
{
}

void MockServerTest::run()
{
    MockServerDaemon daemon;
    MockLogicFacade *logicFacade = daemon.logicFacade();

    BEGIN_TEST(MockServerTest);
    tester()->echo("Configuration:");
    tester()->echo("Duration", CPS_MOCKSERVER_TEST_RUN_DURATION);
#ifdef CPS_MOCKSERVER_SUPPRESS_TASK_OUTPUT
    tester()->echo("Task output suppressed.");
#endif
#ifdef CPS_MOCKSERVER_SUPPRESS_SERVER_SUMMARY_OUTPUT
    tester()->echo("Server summary output suppressed.");
#endif

    int result = daemon();
    PRINT_RETURN(result);

#ifndef CPS_MOCKSERVER_SUPPRESS_SERVER_SUMMARY_OUTPUT
    tester()->echo("total tasks (excluding maintenance)", logicFacade->totalDataCount());
    tester()->echo("rawDataCreations(1)", logicFacade->rawDataCreations(1));
    tester()->echo("rawDataCreations(2)", logicFacade->rawDataCreations(2));
    tester()->echo("taskExecutions(1)", logicFacade->taskExecutions(1));
    tester()->echo("taskExecutions(2)", logicFacade->taskExecutions(2));
    tester()->echo("rawDataReadings()", logicFacade->rawDataReadings());
    tester()->echo("rawDataWritings()", logicFacade->rawDataWritings());
#endif

    const int ExpectedMaintenanceTasks = 1;

    VERIFY(!result, "WorkLoop::execute()");
    COMPARE(logicFacade->rawDataCreations(1), logicFacade->taskExecutions(1), "Task 1 runs");
    COMPARE(logicFacade->rawDataCreations(2), logicFacade->taskExecutions(2), "Task 2 runs");
    COMPARE(logicFacade->rawDataReadings(), logicFacade->rawDataWritings(), "Data read-write");
    COMPARE(logicFacade->rawDataReadings(), logicFacade->totalDataCount() + ExpectedMaintenanceTasks, "Data creation-read");
    END_TEST(MockServerTest);
}

MockServerTest::~MockServerTest()
{
}

} // namespace Cps
