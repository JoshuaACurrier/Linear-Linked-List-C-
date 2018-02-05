# cmake_minimum_required(VERSION <specify CMake version here>)
project(LLL)

set(CMAKE_CXX_STANDARD 11)

add_executable(LLL main.cpp Node.cpp Node.h List.cpp List.h)