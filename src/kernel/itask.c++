#include "itask.h"

namespace Cps {

ITask::ITask()
    : IRunnable()
{
    // no-op
}

void ITask::run()
{
    IRunnable::run();
}

ITask::~ITask()
{
    // no-op
}

} // namespace Cps
