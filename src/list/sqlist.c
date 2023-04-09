/**
 * @file sqlist.c
 * @author DANIEL HU (shady030314@gmail.com)
 */

#include <list/sqlist.h>

void PrintSqList(SqList* sl) {
  // Abort program if SqLIst is NOT INIT
  Assert(sl, "NOT INIT");

  int clock = 0;
  while (clock < (*sl).length - 1) {
    printf("%d ", (*sl).data[clock]);
    ++clock;
  }
  printf("%d\n", (*sl).data[sl->length - 1]);
}

/* Create a null SqList */
STATUS SqListInit(SqList* sl) {
  (*sl).data = (ElemType*)malloc(INIT * sizeof(ElemType));
  Assert((sl)->data, "MALLOC FAILED!");
  (*sl).length = 0;
  (*sl).size = INIT;

  return SUCCESS;
}

/* Create a SqList which contains $num(<=size) random elements */
STATUS SqListCreate(SqList* sl, int num) {
  Assert(sl, "NOT INIT");
  Assert(num <= sl->size, "OVERFLOW");
  /* `man srand` */
  srand(time(0));
  for (int i = 0; i < num; i++) {
    int r = rand();
    (*sl).data[i] = r;
    ++(*sl).length;
  }

  return SUCCESS;
}

/* Insert `e` into the `ith` spot of SqList */
STATUS SqListInsert(SqList* sl, int ith, ElemType e) {
  Assert(sl, "NOT INIT");
  // 1 <= i <= length
  Assert(ith >= 1 && ith <= (*sl).length + 1, "INVALID INSERTION REQUEST");
  /* re-allocate space if SqList is full */
  if ((*sl).length == (*sl).size) {
    sl->data = realloc((*sl).data, ((*sl).size + INIT) * sizeof(ElemType));
    Assert(sl->data, "RE-ALLOCATION FAILED");
  }

  for (int j = sl->length; j >= ith; j--) {
    sl->data[j] = sl->data[j - 1];
  }

  sl->data[ith - 1] = e;
  sl->length++;

  return SUCCESS;
}

/* Delete the `ith` element in SqList, and return the deleted to `e` */
STATUS SqLisDelete(SqList* sl, int ith, ElemType* e) {
  Assert(sl, "NOT INIT");
  Assert(ith >= 1 && ith <= sl->length, "INVALID DELETION");
  *e = sl->data[ith - 1];

  for (int j = ith; j < sl->length; j++) {
    sl->data[ith - 1] = sl->data[ith];
  }
  sl->length--;

  return SUCCESS;
}

/* Just return the `ith` spot element to `e` */
STATUS SqListSearch(SqList* sl, int ith, ElemType* e) {
  Assert(sl, "NOT INIT");
  Assert(ith >= 1 && ith <= sl->length, "INVALID SEARCH");
  *e = sl->data[ith - 1];

  return SUCCESS;
}

STATUS compare(ElemType x, ElemType y) { return x == y; }

/* Return the satisfied spot(⭐️not index) to `ith`(including mutiple occurs) */
STATUS SqListLocate(SqList* sl, int* ith, ElemType e,
                    STATUS (*compare)(ElemType, ElemType)) {
  Assert(sl, "NOT INIT");
  int j = 0;          // denotes how many times occurs
  bool flag = false;  // denotes if target is found or not
  for (int i = 0; i < sl->length; i++) {
    if (compare(sl->data[i], e)) {
      flag = true;
      ith[j] = i + 1;
      j++;
    }
  }
  ith[j] = 20030314;  // indicates end of ith for printing
  if (!flag) {
    _LOG("NOT FOUND!");
  }

  return SUCCESS;
}

// https://leetcode.cn/problems/merge-two-sorted-lists/
SqList* SqMergeList(SqList* sla, SqList* slb, SqList* new) {
  Assert(sla, "NOT INIT");
  Assert(slb, "NOT INIT");

  ElemType *pa = sla->data, *pb = sla->data;
  ElemType* p = new->data;
  int len = sla->length + slb->length;
  SqListInit(new);
  SqListCreate(new, len);
  while (pa <= sla->data + sla->length - 1 &&
         pb <= slb->data + slb->length - 1) {
    if (*pa <= *pb)
      *p++ = *pa++;  // assign and move ptr forward
    else
      *p++ = *pb++;
  }
  // insert the rest of list to new if one ran out
  while (pa <= sla->data + sla->length - 1) *p++ = *pa++;
  while (pb <= slb->data + slb->length - 1) *p++ = *pb++;

  return new;
}