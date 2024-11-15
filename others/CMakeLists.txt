cmake_minimum_required(VERSION 3.24)
project(cpp_hello)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_hello bubble.cpp swap.h swap.cpp pointer.cpp functionPointer.cpp struct.cpp ManagementSystem.cpp unordered_map.cpp vector.cpp vector.h)
