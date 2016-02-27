#include "itask.h"

namespace ConsProd {

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

} // namespace ConsProd
