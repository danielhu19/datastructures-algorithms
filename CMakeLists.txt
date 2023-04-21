cmake_minimum_required(VERSION 3.22)

project(
  datastructures-algorithms
  VERSION 0.1
  DESCRIPTION
    "Implement basic Data structures in C and essential Algorithms in C++"
  LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(algorithms)
