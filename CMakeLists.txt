cmake_minimum_required(VERSION 3.5)

project(aocpp-2024 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(puzzle/day1)
add_subdirectory(puzzle/day2)
