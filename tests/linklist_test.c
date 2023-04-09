#include <list/linklist.h>

int main(int argc, char **argv) {
  int len;
  int ith[3];
  ElemType e;
  LinkList L;
  LinkListInit(&L);
  // LinkListCreate_head(&L, 6);
  LinkListCreate_tail(&L, 6);
  PrintLinkList(&L);

  LinkListInsert(&L, 6, 1);
  LinkListInsert(&L, 6, 1);
  PrintLinkList(&L);

  LinkListDelete(&L, 1, &e);
  PrintLinkList(&L);
  printf("%d\n", e);

  LinkListLocate(&L, ith, 1, compare);
  int num = sizeof(ith) / sizeof(ith[0]);
  for (int i = 0; i < num - 1; i++) {
    printf("%d ", ith[i]);
  }
  printf("\n");

  LinkListSearch(&L, 1, &e);
  printf("%d\n", e);

  return 0;
}