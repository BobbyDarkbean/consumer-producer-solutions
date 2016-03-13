cmake_minimum_required (VERSION 2.6)

set (LIB cps-kernel)
project (${LIB})

message ("Project ${PROJECT_NAME}")

set (SRC irunnable.c++
         itask.c++
         itaskcreator.c++
         itaskfactory.c++)

set (HDR cps_kernel_global.h
         cps_kernel_shared.h
         irunnable.h
         itask.h
         itaskcreator.h
         itaskfactory.h)

add_definitions (-DCPS_KERNEL_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
