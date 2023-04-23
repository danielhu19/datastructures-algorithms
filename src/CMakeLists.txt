set(HEAD_LIST
    "${datastructures-algorithms_SOURCE_DIR}/include/forehead/include.h"
    "${datastructures-algorithms_SOURCE_DIR}/include/list/sqlist.h"
    "${datastructures-algorithms_SOURCE_DIR}/include/list/linklist.h"
    "${datastructures-algorithms_SOURCE_DIR}/include/stack/sqstack.h"
    "${datastructures-algorithms_SOURCE_DIR}/include/queue/sqqueue.h"
    "${datastructures-algorithms_SOURCE_DIR}/include/queue/linkqueue.h")

set(SRC_List list/sqlist.c list/linklist.c stack/sqstack.c queue/sqqueue.c
             queue/linkqueue.c)

add_library(datastructures ${SRC_List} ${HEAD_LIST})

target_include_directories(datastructures PUBLIC ../include)
