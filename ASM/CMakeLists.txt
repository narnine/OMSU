cmake_minimum_required(VERSION 3.15)
project(fantasy_asm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wno-unused-private-field -Wno-unused-parameter -Wold-style-cast")

add_executable(fantasy_asm main.cpp src/addop.cpp src/andop.cpp src/cmpop.cpp src/interpreter.cpp src/jeqop.cpp src/jgrop.cpp src/jleop.cpp src/jmpop.cpp src/jnqop.cpp src/literalvalue.cpp src/memory.cpp src/movop.cpp src/mulop.cpp src/notop.cpp src/orop.cpp src/registervalue.cpp src/tokenizer.cpp src/parser.cpp)


