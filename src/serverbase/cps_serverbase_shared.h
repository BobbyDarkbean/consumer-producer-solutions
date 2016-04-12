#ifndef _Cps_ServerBase_Shared_h_
#define _Cps_ServerBase_Shared_h_

#include "cps_kernel_global.h"

#ifdef CPS_SERVERBASE_LIB
#define CPS_SERVERBASE_SHARED DECLSPEC_EXPORT
#else
#define CPS_SERVERBASE_SHARED DECLSPEC_IMPORT
#endif

#endif // _Cps_ServerBase_Shared_h_
