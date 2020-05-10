project(TemplateList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wno-unused-private-field -Wunused-parameter -Wsign-conversion -Wold-style-cast")

FILE(GLOB_RECURSE SOURCES_LIST ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.cpp)
