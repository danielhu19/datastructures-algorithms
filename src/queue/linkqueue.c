/**
 * @file linkqueue.c
 * @author DANIEL HU (shady030314@gmail.com)
 * @date 2023-04-08
 */

#include <queue/linkqueue.h>

STATUS InitQueue(LinkQNode *Q) {
  Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
  Assert(Q->front, "ALLOCATE FAILED");
  Q->front->next = NULL;

  return SUCCESS;
}

STATUS DestroyQueue(LinkQNode *Q);
STATUS ClearQueue(LinkQNode *Q);
STATUS QueueEmpty(LinkQNode *Q);
STATUS QueueLength(LinkQNode *Q);
STATUS HeadQueue(LinkQNode *Q, ElemType *e);
STATUS EnQueue(LinkQNode *Q, ElemType *e);
STATUS DeQueue(LinkQNode *Q, ElemType *e);