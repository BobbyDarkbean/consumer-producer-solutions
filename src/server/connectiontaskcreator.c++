#include <memory>
#include <unordered_map>
#include <utility>
#include "iconnectiontaskfactory.h"

#include "connectiontaskcreator.h"

namespace Cps {

namespace {
typedef std::unique_ptr<IConnectionTaskFactory> factory_ptr;
}

struct ConnectionTaskCreatorImplementation
{
public:
    std::unordered_map<int, factory_ptr> factories;
};

ConnectionTaskCreator::ConnectionTaskCreator()
    : ITaskCreator(),
      m(new ConnectionTaskCreatorImplementation)
{
    // no-op
}

ConnectionTask *ConnectionTaskCreator::createTask(int type) const
{
    std::unordered_map<int, factory_ptr>::const_iterator i = m->factories.find(type);
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
    std::unordered_map<int, factory_ptr>::iterator i = m->factories.find(type);
    if (i == m->factories.end())
        i = m->factories.insert(std::make_pair(type, factory_ptr(nullptr))).first;

    i->second.reset(factory);
}

void ConnectionTaskCreator::removeFactory(int type)
{
    std::unordered_map<int, factory_ptr>::iterator i = m->factories.find(type);
    if (i == m->factories.end())
        return;

    m->factories.erase(i);
}

ConnectionTaskCreator::~ConnectionTaskCreator()
{
    delete m;
}

} // namespace Cps
