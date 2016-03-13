#ifndef _Cps_Kernel_Global_h_
#define _Cps_Kernel_Global_h_

#if defined(OS_WIN)
#define DECLSPEC_EXPORT __declspec(dllexport)
#define DECLSPEC_IMPORT __declspec(dllimport)
#else
#define DECLSPEC_EXPORT
#define DECLSPEC_IMPORT
#endif

#define DISABLE_COPY(Class) \
    Class(const Class &) = delete; \
    Class &operator=(const Class &) = delete;

#define DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

#define DECLARE_INDIVIDUAL(Class) \
    DISABLE_COPY(Class) \
    DISABLE_MOVE(Class)

#define DECLARE_IMPLEMENTATION(Class) \
    Class##Implementation *const m;

#define DECLARE_UNIQUE_IMPLEMENTATION(Class) \
    Class##Implementation *const m_##Class##_impl;

#define M_UNIQUE(Class) \
    Class##Implementation *const m = m_##Class##_impl

#endif // _Cps_Kernel_Global_h_
