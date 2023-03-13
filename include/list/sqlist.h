#ifndef SQLIST_H_
#define SQLIST_H_

#include "include.h"
/* static allocation */
// #define MAX 50
// typedef struct{
//   ElemType data[MAX];
//   int length;
// }SqList;

/* dynamic allocation */
typedef struct {
  ElemType* data;
  int length;
  int size;
} SqList;

/* basic operations */
SqList* SqListInit();
STATUS SqListCreate(int num);
STATUS SqListInsert(SqList* s, int ith, ElemType e);
STATUS SqLisDelete(SqList* s, int ith, ElemType* e);
STATUS SqListSearch(SqList* s, int ith, ElemType* e);
STATUS SqListLocate(SqList* s, int* ith, ElemType e);

#endif