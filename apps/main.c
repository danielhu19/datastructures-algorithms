#include <forehead/include.h>
#include <list/sqlist.h>

int main(int argc, char *argv[]) {
  int e;
  int num[5];
  SqList sl;
  SqListInit(&sl);
  SqListCreate(&sl, 5);
  PrintSqList(&sl);

  printf("\n");
  SqListInsert(&sl, 1, 1);
  PrintSqList(&sl);

  printf("\n");
  SqLisDelete(&sl, 5, &e);
  printf("%d\n", e);
  PrintSqList(&sl);

  printf("\n");
  SqListSearch(&sl, 5, &e);
  printf("%d\n", e);
  PrintSqList(&sl);

  printf("\n");
  SqListLocate(&sl, &e, 999, compare);
  PrintSqList(&sl);

  return 0;
}
