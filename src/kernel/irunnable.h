#ifndef _IRunnable_h_
#define _IRunnable_h_

#include "cps_kernel_shared.h"

namespace Cps {

class CPS_KERNEL_SHARED IRunnable
{
public:
    IRunnable();
    virtual void run() = 0;
    virtual ~IRunnable() = 0;

private:
    DECLARE_INDIVIDUAL(IRunnable)
};

} // namespace Cps

#endif // _IRunnable_h_
