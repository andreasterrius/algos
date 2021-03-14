cmake_minimum_required(VERSION 3.17)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)
set(-fsanitize=undefined)

add_executable(Algorithms main.cpp)