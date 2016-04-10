cmake_minimum_required (VERSION 2.6)

set (APP tests)
project (${APP})

message ("Project ${PROJECT_NAME}")

set (BUILD_TEST_MOCK_SERVER ON)

include_directories (../kernel)
include_directories (../serverbase)
include_directories (testbase)

add_subdirectory (testbase)
if (BUILD_TEST_MOCK_SERVER)
    add_subdirectory (mockserver)
    add_definitions (-DRUN_TEST_MOCK_SERVER)
endif ()

set (SRC main.c++)
set (HDR test_config.h)

add_executable (${APP} ${SRC} ${HDR})
target_link_libraries (${APP} cps-kernel)
target_link_libraries (${APP} cps-server-base)
target_link_libraries (${APP} cps-test-base)

if (BUILD_TEST_MOCK_SERVER)
    target_link_libraries (${APP} cps-mock-server)
endif ()
