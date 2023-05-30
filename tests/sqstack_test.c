#include <stack/sqstack.h>

int main() {
  SqStack s;
  int e = 0;
  InitSqStack(&s);
  SqPush(&s, 1);
  SqPush(&s, 4);
  SqPush(&s, 3);
  SqPush(&s, 2);
  SqPop(&s, &e);
  printf("%d\n", e);
  PrintSqStack(&s);
  return 0;
}