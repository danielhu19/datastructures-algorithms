# set(SRC_LIST list/sqlist.c list/linklist.c stack/sqstack.c queue/sqqueue.c
# queue/linkqueue.c tree/bitree.c)
file(GLOB_RECURSE SRC_LIST "${DATASTRUCTURES_ALGORITHMS_SOURCE_DIR}/src/**/*.c")

get_property(HEAD_LIST GLOBAL PROPERTY HEAD_LIST)
add_library(DSA ${SRC_LIST} ${HEAD_LIST})

target_include_directories(
  DSA PUBLIC ${DATASTRUCTURES_ALGORITHMS_SOURCE_DIR}/include)
