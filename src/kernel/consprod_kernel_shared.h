#ifndef _Consprod_Kernel_Shared_h_
#define _Consprod_Kernel_Shared_h_

#include "consprod_kernel_global.h"

#ifdef CONSPROD_KERNEL_LIB
#define CONSPROD_KERNEL_SHARED DECLSPEC_EXPORT
#else
#define CONSPROD_KERNEL_SHARED DECLSPEC_IMPORT
#endif

#endif // _Consprod_Kernel_Shared_h_
