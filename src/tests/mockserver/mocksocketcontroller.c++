#include <list>
#include <random>
#include <chrono>

#include "connectiondata.h"
#include "mocklogicfacade.h"

#include "mocksocketcontroller.h"

namespace Cps {

const int MinInterval = 100;
const int MaxInterval = 500;
const std::chrono::milliseconds InitDelayDuration(10);

const int MinTaskId = 1;
const int MaxTaskId = 2;

const ConnectionData RequestForStop { 0, "stop" };

struct MockSocketControllerImplementation
{
    explicit MockSocketControllerImplementation(MockLogicFacade *);

    std::chrono::steady_clock::time_point timeout;
    std::list<ConnectionData> dataList;

    std::minstd_rand randomizer;
    std::uniform_int_distribution<int> intervalUid;
    std::uniform_int_distribution<int> taskIdUid;
    std::chrono::steady_clock::time_point startTime;

    MockLogicFacade *logicFacade;
};

MockSocketControllerImplementation::MockSocketControllerImplementation(MockLogicFacade *logicFacade)
    : timeout(std::chrono::steady_clock::now() + InitDelayDuration),
      dataList(),
      randomizer(std::chrono::system_clock::now().time_since_epoch().count()),
      intervalUid(MinInterval, MaxInterval),
      taskIdUid(MinTaskId, MaxTaskId),
      startTime(std::chrono::steady_clock::now()),
      logicFacade(logicFacade)
{
}

MockSocketController::MockSocketController(MockLogicFacade *logicFacade)
    : ISocketController(),
      m_MockSocketController_impl(new MockSocketControllerImplementation(logicFacade))
{
}

bool MockSocketController::isReadyToRead() const
{
    M_UNIQUE(MockSocketController);
    if (std::chrono::steady_clock::now() < m->timeout)
        return false;

    std::chrono::seconds testDuration(m->logicFacade->testDuration());
    if (std::chrono::steady_clock::now() > m->startTime + testDuration) {
        m->timeout = std::chrono::steady_clock::now() + testDuration;
        m->dataList.push_back(RequestForStop);
        return true;
    }

    int nextInterval = m->intervalUid(m->randomizer);
    m->timeout = std::chrono::steady_clock::now() + std::chrono::microseconds(nextInterval);
    int taskId = m->taskIdUid(m->randomizer);

    ConnectionData data { 0, std::to_string(taskId) };
    m->dataList.push_back(data);
    m->logicFacade->increaseRawDataCreations(taskId);

    return true;
}

ConnectionData MockSocketController::read()
{
    M_UNIQUE(MockSocketController);
    if (m->dataList.empty())
        return RequestForStop;

    ConnectionData data = std::move(m->dataList.front());
    m->dataList.pop_front();
    m->logicFacade->increaseRawDataReadings();

    return data;
}

void MockSocketController::write(const ConnectionData & /* data */)
{
    M_UNIQUE(MockSocketController);
    m->logicFacade->increaseRawDataWritings();
}

MockSocketController::~MockSocketController()
{
    delete m_MockSocketController_impl;
}

} // namespace Cps
