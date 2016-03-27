#include <memory>
#include <unordered_map>
#include "iconnectiontaskfactory.h"

#include "connectiontaskcreator.h"

namespace Cps {

struct ConnectionTaskCreatorImplementation
{
public:
    std::unordered_map<int, std::unique_ptr<IConnectionTaskFactory>> factories;
};

ConnectionTaskCreator::ConnectionTaskCreator()
    : ITaskCreator(),
      m(new ConnectionTaskCreatorImplementation)
{
}

ConnectionTask *ConnectionTaskCreator::createTask(int type) const
{
    auto i = m->factories.find(type);
    if (i == m->factories.end())
        return nullptr;

    return i->second->create();
}

bool ConnectionTaskCreator::hasFactory(int type) const
{
    return m->factories.find(type) != m->factories.end();
}

void ConnectionTaskCreator::insertFactory(int type, IConnectionTaskFactory *factory)
{
    auto i = m->factories.find(type);
    if (i == m->factories.end())
        i = m->factories.emplace(type, nullptr).first;

    i->second.reset(factory);
}

void ConnectionTaskCreator::removeFactory(int type)
{
    auto i = m->factories.find(type);
    if (i == m->factories.end())
        return;

    m->factories.erase(i);
}

ConnectionTaskCreator::~ConnectionTaskCreator()
{
    delete m;
}

} // namespace Cps
