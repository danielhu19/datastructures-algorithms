cmake_minimum_required(VERSION 3.26)

project(
  DataStrucuresC
  VERSION 0.1
  DESCRIPTION "Implement data structures and basic algorithms in C with CMake"
  LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)
