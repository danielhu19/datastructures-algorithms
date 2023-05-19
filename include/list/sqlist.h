#ifndef SQLIST_H_
#define SQLIST_H_

#define LISTINIT 100
#define ElemType int

#include <forehead/forehead.h>

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
void PrintSqList(SqList* sl);
STATUS SqListInit(SqList* sl);
STATUS SqListCreate(SqList* sl, int num);
STATUS SqListInsert(SqList* sl, int ith, ElemType e);
STATUS SqLisDelete(SqList* sl, int ith, ElemType* e);
STATUS SqListLocate(SqList* sl, int* ith, ElemType e,
                    STATUS (*compare)(ElemType, ElemType));
STATUS SqListSearch(SqList* sl, int ith, ElemType* e);
STATUS compare(ElemType x, ElemType y);

/* application of SqList */
SqList* SqMergeList(SqList* sla, SqList* slb, SqList* new);

#endif
