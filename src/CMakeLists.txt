set(HEAD_LIST "${DataStrucuresC_SOURCE_DIR}/include/forehead/include.h")

add_library(datastrucuresc list/sqlist.c ${HEAD_LIST})

target_include_directories(datastrucuresc PUBLIC ../include)

# target_link_libraries(datastrucuresc PRIVATE )


