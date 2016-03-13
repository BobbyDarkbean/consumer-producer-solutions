#include "iconnectiontaskfactory.h"

namespace Cps {

IConnectionTaskFactory::IConnectionTaskFactory()
    : ITaskFactory()
{
    // no-op
}

ConnectionTask *IConnectionTaskFactory::create() const
{
    return nullptr;
}

IConnectionTaskFactory::~IConnectionTaskFactory()
{
    // no-op
}

} // namespace Cps
