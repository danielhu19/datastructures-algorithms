#include <list/sqlist.h>

void PrintSqList(SqList* sl) {
  Assert(sl, "NOT INIT");

  int clock = 0;
  while (clock < (*sl).length - 1) {
    printf("%d ", (*sl).data[clock]);
    ++clock;
  }
  printf("%d\n", (*sl).data[sl->length - 1]);
}

STATUS SqListInit(SqList* sl) {
  (*sl).data = (ElemType*)malloc(INIT * sizeof(ElemType));
  Assert((sl)->data, "malloc failed!");
  (*sl).length = 0;
  (*sl).size = INIT;

  return SUCCESS;
}

STATUS SqListCreate(SqList* sl, int num) {
  Assert(sl, "NOT INIT");
  srand(time(0));
  for (int i = 0; i < num; i++) {
    int r = rand();
    (*sl).data[i] = r;
    ++(*sl).length;
  }

  return SUCCESS;
}

STATUS SqListInsert(SqList* sl, int ith, ElemType e) {
  Assert(sl, "NOT INIT");
  // 1 <= i <= length
  Assert(ith >= 1 && ith <= (*sl).length + 1, "INVALID INSERTION REQUEST");
  if ((*sl).length == (*sl).size) {
    ElemType* newbase =
        realloc((*sl).data, ((*sl).size + INIT) * sizeof(ElemType));
    Assert(newbase, "RE-ALLOCATION FAILED");
  }

  for (int j = sl->length; j >= ith; j--) {
    sl->data[j] = sl->data[j - 1];
  }
  sl->data[ith - 1] = e;
  sl->length++;

  return SUCCESS;
}

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

STATUS SqListSearch(SqList* sl, int ith, ElemType* e) {
  Assert(sl, "NOT INIT");
  Assert(ith >= 1 && ith <= sl->length, "INVALID SEARCH");
  *e = sl->data[ith - 1];

  return SUCCESS;
}

STATUS compare(ElemType x, ElemType y) { return x == y; }

STATUS SqListLocate(SqList* sl, int* ith, ElemType e,
                    STATUS (*compare)(ElemType, ElemType)) {
  Assert(sl, "NOT INIT");
  int j = 0;
  int flag = 0;
  for (int i = 0; i < sl->length; i++) {
    if (compare(sl->data[i], e)) {
      flag = 1;
      ith[j] = i;
      j++;
    }
  }
  if (!flag) {
    LOG("NOT FOUND!");
  }

  return SUCCESS;
}
