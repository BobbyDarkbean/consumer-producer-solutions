#ifndef _IRunnable_h_
#define _IRunnable_h_

#include "consprod_kernel_shared.h"

namespace ConsProd {

class CONSPROD_KERNEL_SHARED IRunnable
{
public:
    virtual void run() = 0;
    virtual ~IRunnable() = 0;

private:
    DECLARE_INDIVIDUAL(IRunnable)
};

} // namespace ConsProd

#endif // _IRunnable_h_
