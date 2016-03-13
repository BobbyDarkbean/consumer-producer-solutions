#ifndef _TaskFactory_h_
#define _TaskFactory_h_

#include "cps_kernel_shared.h"

namespace Cps {

class ITask;

class CPS_KERNEL_SHARED TaskFactory
{
public:
    TaskFactory();
    virtual ITask *create() const = 0;
    virtual ~TaskFactory() = 0;

private:
    DECLARE_INDIVIDUAL(TaskFactory)
};

} // namespace Cps

#endif // _TaskFactory_h_
