cmake_minimum_required (VERSION 2.6)

set (LIB cps-server-base)
project (${LIB})

message ("Project ${PROJECT_NAME}")

include_directories (../kernel)

set (SRC connectiontask.c++
         connectiontaskcreator.c++
         iconnectiontaskchart.c++
         iconnectiontaskfactory.c++
         intercom.c++
         ireplyencoder.c++
         irequestdecoder.c++
         isocketcontroller.c++
         maintenancetask.c++
         maintenancetaskchart.c++
         maintenancetaskfactory.c++
         requestdata.c++
         servercontext.c++
         taskscheduler.c++
         taskworker.c++
         workloop.c++)

set (HDR connectiondata.h
         connectiontask.h
         connectiontaskcreator.h
         cps_serverbase_shared.h
         iconnectiontaskchart.h
         iconnectiontaskfactory.h
         intercom.h
         ireplyencoder.h
         irequestdecoder.h
         isocketcontroller.h
         maintenancetask.h
         maintenancetaskchart.h
         maintenancetaskfactory.h
         requestdata.h
         servercontext.h
         taskscheduler.h
         taskworker.h
         workloop.h)

add_definitions (-DCPS_SERVERBASE_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
target_link_libraries (${LIB} cps-kernel)
