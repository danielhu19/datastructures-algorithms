/**
 * @file sqqueue.c
 * @author DANIEL HU (shady030314@gmail.com)
 * @date 2023-04-16
 *
 * Circular Queue actually
 */
#include <queue/sqqueue.h>

SqQueue *InitSqQueue() {
  SqQueue *Q = (SqQueue *)malloc(QUEUEMAXSIZE * sizeof(SqQueue));
  Assert(Q, "MALLOC FAILED");
  Q->front = Q->rear = 0;
  return Q;
}

STATUS ClearSqQueue(SqQueue *Q) {
  Assert(Q, "NOT INIT");
  Q->front = Q->rear = 0;

  return SUCCESS;
}

bool SqQueueEmpty(SqQueue *Q) {
  Assert(Q, "NOT INIT");
  return Q->front == Q->rear;
}

int SqQueueLength(SqQueue *Q) {
  Assert(Q, "NOT INIT");
  return (Q->rear - Q->front + QUEUEMAXSIZE) % QUEUEMAXSIZE;
}
void printSqQueue(SqQueue *Q) {
  Assert(Q, "NOT INIT");
  if (SqQueueEmpty(Q)) {
    LOG("NULL");
    return;
  }
  int len = (Q->rear - Q->front + QUEUEMAXSIZE) % QUEUEMAXSIZE;
  for (int i = 0; i < len; ++i) {
    printf("%d ", Q->data[i]);
  }
  printf("\n");
}

STATUS EnSqQueue(SqQueue *Q, int e) {
  Assert(Q, "NOT INIT");
  if ((Q->rear + 1) % QUEUEMAXSIZE == Q->front) return FAILURE;  // Full Queue
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % QUEUEMAXSIZE;
  return SUCCESS;
}

STATUS DeSqQueue(SqQueue *Q, int *e) {
  Assert(Q, "NOT INIT");
  if (Q->rear == Q->front) return FAILURE;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % QUEUEMAXSIZE;
  return SUCCESS;
}
