cmake_minimum_required(VERSION 3.11)
project(advanced_ca_2 C CXX)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(PAPI)

set(CMAKE_C_FLAGS_RELEASE "-O2 -DPAPI")

add_executable(array_sum array_sum.c)

target_include_directories(array_sum PUBLIC ${PAPI_INCLUDE_DIRS})
target_link_libraries(array_sum PUBLIC ${PAPI_LIBRARIES})
