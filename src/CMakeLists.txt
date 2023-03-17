set(HEAD_LIST
    "${DataStrucuresC_SOURCE_DIR}/include/forehead/include.h"
    "${DataStrucuresC_SOURCE_DIR}/include/list/sqlist.h"
    "${DataStrucuresC_SOURCE_DIR}/include/list/linklist.h")

set(SRC_List list/sqlist.c list/linklist.c)

add_library(datastrucuresc ${SRC_List} ${HEAD_LIST})

target_include_directories(datastrucuresc PUBLIC ../include)
