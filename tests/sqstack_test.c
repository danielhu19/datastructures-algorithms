#include <stack/sqstack.h>

int main() {
  SqStack s;
  int e = 0;
  InitSqStack(&s);
  Sq_Push(&s, 1);
  Sq_Push(&s, 4);
  Sq_Push(&s, 3);
  Sq_Push(&s, 2);
  Sq_Pop(&s, &e);
  printf("%d\n", e);
  PrintSqStack(&s);
  return 0;
}