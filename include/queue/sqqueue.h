#ifndef SQQUEUE_H_
#define SQQUEUE_H_

#include <forehead/forehead.h>
#define QUEUEMAXSIZE 5
#define ElemType int

typedef struct {
  ElemType data[QUEUEMAXSIZE];  // static allocation
  int front;
  int rear;
} SqQueue;

SqQueue *InitSqQueue();
STATUS DestroySqQueue(SqQueue *Q);
STATUS ClearSqQueue(SqQueue *Q);
bool SqQueueEmpty(SqQueue *Q);
int SqQueueLength(SqQueue *Q);
void printSqQueue(SqQueue *Q);
STATUS EnSqQueue(SqQueue *Q, int e);
STATUS DeSqQueue(SqQueue *Q, int *e);

#endif
