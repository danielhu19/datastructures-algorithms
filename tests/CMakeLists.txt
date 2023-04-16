add_executable(sqlist sqlist_test.c)
add_executable(linklist linklist_test.c)
add_executable(sqstack sqstack_test.c)
add_executable(queue queue_test.c)

target_link_libraries(sqlist PUBLIC datastrucuresc)
target_link_libraries(linklist PUBLIC datastrucuresc)
target_link_libraries(sqstack PUBLIC datastrucuresc)
target_link_libraries(queue PUBLIC datastrucuresc)
