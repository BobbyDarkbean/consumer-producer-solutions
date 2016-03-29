#ifndef _Cps_MockServer_Shared_h_
#define _Cps_MockServer_Shared_h_

#include "cps_kernel_global.h"

#ifdef CPS_MOCKSERVER_LIB
#define CPS_MOCKSERVER_SHARED DECLSPEC_EXPORT
#else
#define CPS_MOCKSERVER_SHARED DECLSPEC_IMPORT
#endif

#endif // _Cps_MockServer_Shared_h_
