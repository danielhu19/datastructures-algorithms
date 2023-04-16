#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

#include <forehead/include.h>

typedef struct QNode {
  ElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
} LinkQNode;

STATUS InitQueue(LinkQNode *Q);
STATUS DestroyQueue(LinkQNode *Q);
STATUS ClearQueue(LinkQNode *Q);
STATUS QueueEmpty(LinkQNode *Q);
int QueueLength(LinkQNode *Q);
STATUS HeadQueue(LinkQNode *Q, ElemType *e);
STATUS EnQueue(LinkQNode *Q, ElemType e);
STATUS DeQueue(LinkQNode *Q, ElemType *e);
void printLinkQueue(LinkQNode *Q);

#endif