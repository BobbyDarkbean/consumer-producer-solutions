cmake_minimum_required (VERSION 2.6)

set (LIB cps-server-base)
project (${LIB})

message ("Project ${PROJECT_NAME}")

include_directories (../kernel)

set (SRC connectiontask.c++
         connectiontaskcreator.c++
         iconnectiontaskchart.c++
         iconnectiontaskfactory.c++
         ireplyencoder.c++
         irequestdecoder.c++
         isocketcontroller.c++
         requestdata.c++
         taskscheduler.c++
         taskworker.c++
         workloop.c++)

set (HDR connectiondata.h
         connectiontask.h
         connectiontaskcreator.h
         cps_server_shared.h
         iconnectiontaskchart.h
         iconnectiontaskfactory.h
         ireplyencoder.h
         irequestdecoder.h
         isocketcontroller.h
         requestdata.h
         taskscheduler.h
         taskworker.h
         workloop.h)

add_definitions (-DCPS_SERVER_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
target_link_libraries (${LIB} cps-kernel)
