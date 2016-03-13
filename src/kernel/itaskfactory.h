#ifndef _ITaskFactory_h_
#define _ITaskFactory_h_

#include "cps_kernel_shared.h"

namespace Cps {

class ITask;

class CPS_KERNEL_SHARED ITaskFactory
{
public:
    ITaskFactory();
    virtual ITask *create() const = 0;
    virtual ~ITaskFactory() = 0;

private:
    DECLARE_INDIVIDUAL(ITaskFactory)
};

} // namespace Cps

#endif // _ITaskFactory_h_
