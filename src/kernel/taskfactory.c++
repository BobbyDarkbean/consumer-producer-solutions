#include "taskfactory.h"

namespace ConsProd {

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

} // namespace ConsProd
