#ifndef _ITaskCreator_h_
#define _ITaskCreator_h_

#include "cps_kernel_shared.h"

namespace Cps {

class ITask;

class CPS_KERNEL_SHARED ITaskCreator
{
public:
    ITaskCreator();
    virtual ITask *createTask(int type) const = 0;
    virtual ~ITaskCreator() = 0;

private:
    DECLARE_INDIVIDUAL(ITaskCreator)
};

} // namespace Cps

#endif // _ITaskCreator_h_
