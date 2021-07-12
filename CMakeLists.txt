cmake_minimum_required(VERSION 3.13)
project(advanced_ca_2 C CXX)

set(CMAKE_C_FLAGS_RELEASE "-O2")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(PAPI)
find_package(OpenMP)

add_executable(dotp_omp dotp_omp.c)

target_include_directories(dotp_omp PUBLIC ${PAPI_INCLUDE_DIRS})
target_link_libraries(dotp_omp PUBLIC OpenMP::OpenMP_C)
target_link_libraries(dotp_omp PUBLIC ${PAPI_LIBRARIES})
