cmake_minimum_required(VERSION 3.24.2)
project(Sx1280Demo C CXX)

include("${CMAKE_CURRENT_LIST_DIR}/lib/fprime/cmake/FPrime.cmake")
fprime_setup_included_code()

include("${CMAKE_CURRENT_LIST_DIR}/lib/fprime-sx1280/library.cmake")

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Sx1280Demo")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/RadioDemo")
