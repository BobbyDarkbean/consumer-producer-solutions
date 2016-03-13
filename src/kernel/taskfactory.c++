#include "taskfactory.h"

namespace Cps {

TaskFactory::TaskFactory()
{
    // no-op
}

ITask *TaskFactory::create() const
{
    return nullptr;
}

TaskFactory::~TaskFactory()
{
    // no-op
}

} // namespace Cps
