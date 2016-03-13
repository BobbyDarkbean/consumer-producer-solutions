#include "itaskcreator.h"

namespace Cps {

ITaskCreator::ITaskCreator()
{
    // no-op
}

ITask *ITaskCreator::createTask(int /* type */) const
{
    return nullptr;
}

ITaskCreator::~ITaskCreator()
{
    // no-op
}

} // namespace Cps
