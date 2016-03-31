#ifndef _Cps_Testbase_Shared_h_
#define _Cps_Testbase_Shared_h_

#include "cps_kernel_global.h"

#ifdef CPS_TESTBASE_LIB
#define CPS_TESTBASE_SHARED DECLSPEC_EXPORT
#else
#define CPS_TESTBASE_SHARED DECLSPEC_IMPORT
#endif

#endif // _Cps_Testbase_Shared_h_
