cmake_minimum_required (VERSION 2.6)

set (LIB cps-test-base)
project (${LIB})

message ("Project ${PROJECT_NAME}")

include_directories (../../kernel)

set (SRC test.c++
         tester.c++)

set (HDR cps_testbase_shared.h
         test.h
         tester.h)

add_definitions (-DCPS_TESTBASE_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
target_link_libraries (${LIB} cps-kernel)
