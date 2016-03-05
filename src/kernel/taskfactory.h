#ifndef _TaskFactory_h_
#define _TaskFactory_h_

#include "consprod_kernel_shared.h"

namespace ConsProd {

class ITask;

class CONSPROD_KERNEL_SHARED TaskFactory
{
public:
    TaskFactory();
    virtual ITask *create() const = 0;
    virtual ~TaskFactory() = 0;

private:
    DECLARE_INDIVIDUAL(TaskFactory)
};

} // namespace ConsProd

#endif // _TaskFactory_h_
