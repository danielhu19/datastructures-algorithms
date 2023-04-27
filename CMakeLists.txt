cmake_minimum_required(VERSION 3.22)

project(
  datastructures-algorithms
  VERSION 0.1
  DESCRIPTION
    "Implement basic Data structures in C and essential Algorithms in C++"
  LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm@16/bin/clang)
set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm@16/bin/clang++)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(algorithms)
