/**
 * @file linkqueue.c
 * @author DANIEL HU (shady030314@gmail.com)
 * @date 2023-04-08
 */

#include <queue/linkqueue.h>

/* Initialize a null LinkedQueue */
STATUS InitQueue(LinkQNode *Q) {
  Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
  Assert(Q->front, "ALLOCATE FAILED");
  Q->front->next = NULL;

  return SUCCESS;
}

/* Destroy a Queue one by one */
STATUS DestroyQueue(LinkQNode *Q) {
  Assert(Q->front, "NOT INIT");
  while (Q->front) {
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return SUCCESS;
}

/* Empty the queue, keep the head */
STATUS ClearQueue(LinkQNode *Q) {
  Assert(Q->front, "NOT INIT");
  QueuePtr p, q;
  // NULL QUEUE
  Q->rear = Q->front;
  /* free the rest of memory */
  p = Q->front->next;
  while (p) {
    q = p;
    p = p->next;
    free(q);
  }

  return SUCCESS;
}

/* return if queue is empty */
STATUS QueueEmpty(LinkQNode *Q) {
  Assert(Q->front, "NOT INIT");
  return Q->rear == Q->front;
}

/* return the length of queue */
int QueueLength(LinkQNode *Q) {
  Assert(Q->front, "NOT INIT");
  if (Q->front == Q->rear) {
    LOG("NULL QUEUE!");
    return 0;
  }
  int length = 0;
  QueuePtr ptr = Q->front;

  while (ptr != Q->rear) {
    ptr = ptr->next;
    ++length;
  }

  return length;
}

/**
 * Return the VALUE of front queue element to given `e`
 *
 * 0: null queue
 */
STATUS HeadQueue(LinkQNode *Q, ElemType *e) {
  Assert(Q->front, "NOT INIT");
  if (Q->front == Q->rear) return 0;
  *e = Q->front->next->data;

  return SUCCESS;
}

/* EnterQueue only operates at the rear of queue */
STATUS EnQueue(LinkQNode *Q, ElemType e) {
  Assert(Q->front, "NOT INIT");
  QueuePtr ptr = (QueuePtr)malloc(sizeof(QNode));
  Assert(ptr, "MALLOC FAILED");
  ptr->data = e;
  ptr->next = NULL;
  Q->rear->next = ptr;
  Q->rear = ptr;
  return SUCCESS;
}

/* DeleteQueue only operates at the head of queue */
STATUS DeQueue(LinkQNode *Q, ElemType *e) {
  Assert(Q->front, "NOT INIT");
  if (Q->front == Q->rear) return 0;
  *e = Q->front->next->data;
  QueuePtr tmp = Q->front->next;
  Q->front->next = tmp->next;
  // if there is only one element in queue
  if (Q->rear == tmp) Q->rear = Q->front;
  free(tmp);
  return SUCCESS;
}

/* print queue from head to rear */
void printLinkQueue(LinkQNode *Q) {
  Assert(Q->front, "NOT INIT");
  QueuePtr p = Q->front->next;
  while (p != Q->rear) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("%d\n", p->data);
}