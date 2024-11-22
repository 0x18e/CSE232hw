# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project ("CSE232")
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.h")

add_executable(PROJECT_NAME ${SOURCES})
