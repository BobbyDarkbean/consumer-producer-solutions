#ifndef _Cps_Kernel_Shared_h_
#define _Cps_Kernel_Shared_h_

#include "cps_kernel_global.h"

#ifdef CPS_KERNEL_LIB
#define CPS_KERNEL_SHARED DECLSPEC_EXPORT
#else
#define CPS_KERNEL_SHARED DECLSPEC_IMPORT
#endif

#endif // _Cps_Kernel_Shared_h_
