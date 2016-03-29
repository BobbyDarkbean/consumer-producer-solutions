cmake_minimum_required (VERSION 2.6)

set (LIB cps-mock-server)
project (${LIB})

message ("Project ${PROJECT_NAME}")

# Configuration
set (TEST_RUN_DURATION 1) # in seconds
set (SUPPRESS_TASK_OUTPUT ON)
set (SUPPRESS_SERVER_SUMMARY_OUTPUT ON)
# -------------

include_directories (../../kernel)
include_directories (../../serverbase)
include_directories (../testbase)

set (SRC mocklogicfacade.c++
         mockreplyencoder.c++
         mockrequestdecoder.c++
         mockserverdaemon.c++
         mockservertest.c++
         mocksocketcontroller.c++
         mocktask.c++
         mocktaskchart.c++
         mocktaskfactory.c++)

set (HDR cps_mockserver_shared.h
         mocklogicfacade.h
         mockreplyencoder.h
         mockrequestdecoder.h
         mockserverdaemon.h
         mockservertest.h
         mocksocketcontroller.h
         mocktask.h
         mocktaskchart.h
         mocktaskfactory.h)

add_definitions (-DCPS_MOCKSERVER_LIB)
if (SUPPRESS_TASK_OUTPUT)
    add_definitions (-DCPS_MOCKSERVER_SUPPRESS_TASK_OUTPUT)
endif ()
if (SUPPRESS_SERVER_SUMMARY_OUTPUT)
    add_definitions (-DCPS_MOCKSERVER_SUPPRESS_SERVER_SUMMARY_OUTPUT)
endif ()
add_definitions (-DCPS_MOCKSERVER_TEST_RUN_DURATION=${TEST_RUN_DURATION})

add_library (${LIB} SHARED ${SRC} ${HDR})
target_link_libraries (${LIB} cps-kernel)
target_link_libraries (${LIB} cps-server-base)
target_link_libraries (${LIB} cps-test-base)
