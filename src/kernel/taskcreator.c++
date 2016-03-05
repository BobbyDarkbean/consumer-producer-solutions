#include <memory>
#include <unordered_map>
#include <utility>
#include "taskfactory.h"

#include "taskcreator.h"

namespace ConsProd {

class TaskCreatorImplementation
{
public:
    std::unordered_map<int, std::unique_ptr<TaskFactory>> factories;
};

TaskCreator::TaskCreator()
    : m(new TaskCreatorImplementation)
{
    // no-op
}

ITask *TaskCreator::createTask(int type) const
{
    std::unordered_map<int, std::unique_ptr<TaskFactory>>::const_iterator i = m->factories.find(type);
    if (i == m->factories.end())
        return nullptr;

    return i->second->create();
}

bool TaskCreator::hasFactory(int type) const
{
    return m->factories.find(type) != m->factories.end();
}

void TaskCreator::insertFactory(int type, TaskFactory *factory)
{
    std::unordered_map<int, std::unique_ptr<TaskFactory>>::iterator i = m->factories.find(type);
    if (i == m->factories.end())
        i = m->factories.insert(std::make_pair(type, std::unique_ptr<TaskFactory>(nullptr))).first;

    i->second.reset(factory);
}

void TaskCreator::removeFactory(int type)
{
    std::unordered_map<int, std::unique_ptr<TaskFactory>>::iterator i = m->factories.find(type);
    if (i == m->factories.end())
        return;

    m->factories.erase(i);
}

TaskCreator::~TaskCreator()
{
    delete m;
}

} // namespace ConsProd
