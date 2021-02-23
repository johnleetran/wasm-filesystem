cmake_minimum_required(VERSION 3.12)

project(filesystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set( CMAKE_CXX_FLAGS "-D__EMSCRIPTEN__" )
set(EMCC_LINKER_FLAGS "-Wall --bind")

# add_executable( main main.cpp )
add_library( filesystem STATIC main.cpp )