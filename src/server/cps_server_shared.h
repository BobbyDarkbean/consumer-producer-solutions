#ifndef _Cps_Server_Shared_h_
#define _Cps_Server_Shared_h_

#include "cps_kernel_global.h"

#ifdef CPS_SERVER_LIB
#define CPS_SERVER_SHARED DECLSPEC_EXPORT
#else
#define CPS_SERVER_SHARED DECLSPEC_IMPORT
#endif

#endif // _Cps_Server_Shared_h_
