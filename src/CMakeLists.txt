set(HEAD_LIST "${DataStrucuresC_SOURCE_DIR}/include/forehead/include.h"
              "${DataStrucuresC_SOURCE_DIR}/include/list/sqlist.h"
              )

set(SRC_List list/sqlist.c
  )

add_library(datastrucuresc ${SRC_List} ${HEAD_LIST})

target_include_directories(datastrucuresc PUBLIC ../include)
