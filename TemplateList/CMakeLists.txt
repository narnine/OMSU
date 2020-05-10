cmake_minimum_required(VERSION 3.15)
project(TemplateList)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

include(CMake/googletest.cmake)
fetch_googletest(${PROJECT_SOURCE_DIR}/CMake ${PROJECT_BINARY_DIR}/googletest)
enable_testing()
add_subdirectory(tests)

add_subdirectory(include)
