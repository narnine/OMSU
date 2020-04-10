cmake_minimum_required(VERSION 3.12)
project(list_project C)

set(CMAKE_CXX_STANDARD 14)

add_executable(list_project main.c
        linked_list.c
        #array_list.c
        )
