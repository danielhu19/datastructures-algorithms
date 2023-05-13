# just add_executable() for debug and testing algorithms add_executable(polish
# polish.cpp)
add_executable(array ./array/dualptr.cpp)
add_executable(lklist ./linkedlist/doubleptr.c)
target_link_libraries(lklist PUBLIC datastructures)
