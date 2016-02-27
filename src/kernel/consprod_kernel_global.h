#ifndef _Consprod_Kernel_Global_h_
#define _Consprod_Kernel_Global_h_

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

#endif // _Consprod_Kernel_Global_h_
