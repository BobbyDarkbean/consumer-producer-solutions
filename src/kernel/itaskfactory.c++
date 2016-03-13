#include "itaskfactory.h"

namespace Cps {

ITaskFactory::ITaskFactory()
{
    // no-op
}

ITask *ITaskFactory::create() const
{
    return nullptr;
}

ITaskFactory::~ITaskFactory()
{
    // no-op
}

} // namespace Cps
