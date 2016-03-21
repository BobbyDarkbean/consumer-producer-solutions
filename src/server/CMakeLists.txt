cmake_minimum_required (VERSION 2.6)

set (LIB cps-server)
project (${LIB})

message ("Project ${PROJECT_NAME}")

include_directories (../kernel)

set (SRC connectiontask.c++
         connectiontaskcreator.c++
         iconnectiontaskfactory.c++
         ireplyencoder.c++
         irequestdecoder.c++
         taskworker.c++)

set (HDR connectiontask.h
         connectiontaskcreator.h
         cps_server_shared.h
         iconnectiontaskfactory.h
         ireplyencoder.h
         irequestdecoder.h
         requestdata.h
         taskworker.h)

add_definitions (-DCPS_SERVER_LIB)

add_library (${LIB} SHARED ${SRC} ${HDR})
target_link_libraries (${LIB} cps-kernel)
