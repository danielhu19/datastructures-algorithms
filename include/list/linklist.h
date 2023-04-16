#ifndef LINKLIST_H_
#define LINKLIST_H_
#include <forehead/include.h>

#define LISTMAXSIZE 10

// single linked list
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

void PrintLinkList(LinkList *l);
int LinkListLen(LinkList *l);
STATUS LinkListInit(LinkList *l);
STATUS LinkListCreate_head(LinkList *l, int num);
STATUS LinkListCreate_tail(LinkList *l, int num);
STATUS LinkListInsert(LinkList *l, int ith, ElemType e);
STATUS LinkListDelete(LinkList *l, int ith, ElemType *e);
STATUS LinkListLocate(LinkList *l, int *ith, ElemType e,
                      int (*compare)(ElemType, ElemType));
STATUS LinkListSearch(LinkList *l, int ith, ElemType *e);
STATUS compare(ElemType x, ElemType y);

// double linked list
typedef struct DNode {
  ElemType data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

// static linked list
typedef struct SNode {
  ElemType data;
  int next;
} SLinkList[LISTMAXSIZE];

#endif