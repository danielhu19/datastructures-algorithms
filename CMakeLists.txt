cmake_minimum_required(VERSION 3.22)
project(DataStructuresC)

add_subdirectory(header)

add_executable(datastructure main.c)
target_link_libraries(datastructure head)
