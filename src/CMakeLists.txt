cmake_minimum_required (VERSION 2.6)

set (PROJ consumer-producer-solutions)
project (${PROJ})

message ("Project ${PROJECT_NAME}")

if (WIN32)
    add_definitions (-DOS_WIN)
endif ()

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

if (CMAKE_COMPILER_IS_GNUCXX)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -pedantic -s -std=c++0x")
endif ()

add_subdirectory (kernel)
add_subdirectory (serverbase)
