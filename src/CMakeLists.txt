set(HEAD_LIST
    "${DataStrucuresC_SOURCE_DIR}/include/forehead/include.h"
    "${DataStrucuresC_SOURCE_DIR}/include/list/sqlist.h"
    "${DataStrucuresC_SOURCE_DIR}/include/list/linklist.h"
    "${DataStrucuresC_SOURCE_DIR}/include/stack/sqstack.h"
    "${DataStrucuresC_SOURCE_DIR}/include/queue/sqqueue.h"
    "${DataStrucuresC_SOURCE_DIR}/include/queue/linkqueue.h")

set(SRC_List list/sqlist.c list/linklist.c stack/sqstack.c queue/sqqueue.c
             queue/linkqueue.c)

add_library(datastrucuresc ${SRC_List} ${HEAD_LIST})

target_include_directories(datastrucuresc PUBLIC ../include)
