cmake_minimum_required(VERSION 3.15)
project(SmartPointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(SmartPointer main.cpp src/scoped_ptr.cpp)