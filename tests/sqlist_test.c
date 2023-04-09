#include <list/sqlist.h>

int main(int argc, char *argv[]) {
  int e;
  int ith[3];
  SqList sl;
  SqListInit(&sl);
  SqListCreate(&sl, 5);
  PrintSqList(&sl);

  printf("\n");
  SqListInsert(&sl, 1, 1);
  SqListInsert(&sl, 3, 1);
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
  SqListLocate(&sl, ith, 1, compare);
  int num = sizeof(ith) / sizeof(ith[0]);
  for (int i = 0; i < num - 1; i++) {
    printf("%d ", ith[i]);
  }
  printf("\n");

  return 0;
}
