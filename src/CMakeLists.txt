# set(head_list
# "${datastructures-algorithms_source_dir}/include/forehead/include.h"
# "${datastructures-algorithms_source_dir}/include/list/sqlist.h"
# "${datastructures-algorithms_source_dir}/include/list/linklist.h"
# "${datastructures-algorithms_source_dir}/include/stack/sqstack.h"
# "${datastructures-algorithms_source_dir}/include/queue/sqqueue.h"
# "${datastructures-algorithms_source_dir}/include/queue/linkqueue.h"
# "${datastructures-algorithms_source_dir}/include/tree/bitree.h"
# "${datastructures-algorithms_source_dir}/include/tree/tree.h")

set(head_list "")
file(GLOB_RECURSE head_list
     "${datastructures-algorithms_source_dir}/include/**/*.h")

set(SRC_List list/sqlist.c list/linklist.c stack/sqstack.c queue/sqqueue.c
             queue/linkqueue.c tree/bitree.c)

add_library(datastructures ${SRC_List} ${HEAD_LIST})

target_include_directories(datastructures PUBLIC ../include)
