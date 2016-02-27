cmake_minimum_required (VERSION 2.6)

set (LIB cons-prod-kernel)
project (${LIB})

message ("Project ${PROJECT_NAME}")

set (SRC irunnable.c++)

set (HDR consprod_kernel_global.h
         consprod_kernel_shared.h
         irunnable.h)

add_definitions (-DCONSPROD_KERNEL_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
