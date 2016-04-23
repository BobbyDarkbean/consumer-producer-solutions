#include <map>
#include <memory>
#include <atomic>

#include "mocklogicfacade.h"

namespace Cps {

const int TaskCount = 2;
const int DefaultTestDuration = 5;

struct MockLogicFacadeImplementation
{
    MockLogicFacadeImplementation();

    typedef std::unique_ptr<std::atomic<int>> AtomicIntPtr;

    std::map<int, AtomicIntPtr> rawDataCreations;
    std::map<int, AtomicIntPtr> taskExecutions;
    std::atomic<int> rawDataReadings;
    std::atomic<int> rawDataWritings;

    int testDuration;
};

MockLogicFacadeImplementation::MockLogicFacadeImplementation()
    : rawDataCreations(),
      taskExecutions(),
      rawDataReadings(0),
      rawDataWritings(0),
      testDuration(DefaultTestDuration)
{
    for (int i = 1; i <= TaskCount; ++i) {
        rawDataCreations.emplace(i, AtomicIntPtr(new std::atomic<int>(0)));
        taskExecutions.emplace(i, AtomicIntPtr(new std::atomic<int>(0)));
    }
}

MockLogicFacade::MockLogicFacade()
    : m(new MockLogicFacadeImplementation)
{
}

int MockLogicFacade::totalDataCount() const
{
    int sum = 0;
    for (const auto &i: m->rawDataCreations)
        sum += i.second->load(std::memory_order_acquire);
    return sum;
}

int MockLogicFacade::rawDataCreations(int type) const
{ return m->rawDataCreations[type]->load(std::memory_order_acquire); }

int MockLogicFacade::taskExecutions(int type) const
{ return m->taskExecutions[type]->load(std::memory_order_acquire); }

int MockLogicFacade::rawDataReadings() const
{ return m->rawDataReadings.load(std::memory_order_acquire); }

int MockLogicFacade::rawDataWritings() const
{ return m->rawDataWritings.load(std::memory_order_acquire); }

void MockLogicFacade::increaseRawDataCreations(int type)
{ m->rawDataCreations[type]->fetch_add(1); }

void MockLogicFacade::increaseTaskExecutions(int type)
{ m->taskExecutions[type]->fetch_add(1); }

void MockLogicFacade::increaseRawDataReadings()
{ m->rawDataReadings.fetch_add(1); }

void MockLogicFacade::increaseRawDataWritings()
{ m->rawDataWritings.fetch_add(1); }

int MockLogicFacade::testDuration() const
{ return m->testDuration; }

void MockLogicFacade::setTestDuration(int secs)
{ m->testDuration = secs; }

MockLogicFacade::~MockLogicFacade()
{
    delete m;
}

} // namespace Cps
