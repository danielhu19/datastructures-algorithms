#include <queue/linkqueue.h>
#include <queue/sqqueue.h>

int main() {
  /*Linked Queue part*/
  // LinkQNode q;
  // int e = 0;
  // InitQueue(&q);
  // EnQueue(&q, 10);
  // EnQueue(&q, 1);
  // EnQueue(&q, 2);
  // EnQueue(&q, 3);
  // printLinkQueue(&q);
  // EnQueue(&q, 0);
  // DeQueue(&q, &e);
  // printf("%d\n", e);
  // HeadQueue(&q, &e);
  // printLinkQueue(&q);
  // printf("Len: %d, Head:%d\n", QueueLength(&q), e);

  /* Circular Queue*/
  int e = 0;
  SqQueue *s = InitSqQueue();
  EnSqQueue(s, 0);
  EnSqQueue(s, 1);
  printSqQueue(s);
  DeSqQueue(s, &e);
  printf("%d\n", e);
  printSqQueue(s);
  return 0;
}