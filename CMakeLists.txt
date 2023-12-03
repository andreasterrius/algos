cmake_minimum_required(VERSION 3.17)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(-fsanitize=undefined)

configure_file(randomizer/randomizer_meta.hpp.in ${CMAKE_SOURCE_DIR}/randomizer/randomizer_meta.hpp)

add_executable(Algorithms main.cpp)
add_executable(Randomizer randomizer/randomizer.cpp)