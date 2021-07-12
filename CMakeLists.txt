cmake_minimum_required(VERSION 3.11)
project(advanced_ca_2 C CXX)
find_package(OpenMP)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(PAPI)

set(CMAKE_C_FLAGS_RELEASE "-O2")

add_executable(dotp_omp dotp_omp.c)

target_include_directories(dotp_omp PUBLIC ${PAPI_INCLUDE_DIRS})
target_link_libraries(dotp_omp PUBLIC OpenMP::OpenMP_C)
target_link_libraries(dotp_omp PUBLIC ${PAPI_LIBRARIES})
