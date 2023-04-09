#include <list/linklist.h>

/* Note: LinkList is a pointer which pointes to Node.
   l(LinkList *l) is the pointer which points to LinkList. */

void PrintLinkList(LinkList *l) {
  Assert(l, "NOT INIT");
  LinkList ptr = (*l)->next;
  while (ptr->next != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d\n", ptr->data);
}

/* Init a HeadNode which represents NULL Linked List */
STATUS LinkListInit(LinkList *l) {
  *l = (LNode *)malloc(sizeof(LNode));
  Assert(*l, "INIT FAILED!");
  (*l)->next = NULL;

  return SUCCESS;
}

/** Return the length of LinkList */
int LinkListLen(LinkList *l) {
  int len = 0;
  LinkList ptr = (*l)->next;
  while (ptr->next != NULL) {
    len++;
    ptr = ptr->next;
  }
  return len + 1;
}

/* Create a linked list with SERIATE ORDER (Tail Insert) */
STATUS LinkListCreate_tail(LinkList *l, int num) {
  Assert(*l, "NOT INIT");
  LinkList ptr = *l;
  srand(time(0));
  for (int i = 0; i < num; i++) {
    LinkList node = (LinkList)malloc(sizeof(LNode));
    Assert(node, "MALLOC FAILED");
    ptr->next = node;
    node->data = rand();
    node->next = NULL;
    // ptr always points to new node
    ptr = ptr->next;
  }

  return SUCCESS;
}

/* Create a linked list with INVERSE ORDER (Head Insert)*/
STATUS LinkListCreate_head(LinkList *l, int num) {
  Assert(*l, "NOT INIT");
  LinkList ptr = *l;
  srand(time(0));
  for (int i = 0; i < num; i++) {
    LinkList node = (LinkList)malloc(sizeof(LNode));
    Assert(node, "MALLOC FAILED");
    node->data = rand();
    // New node becomes the FIRST-NODE
    node->next = ptr->next;
    ptr->next = node;
  }

  return SUCCESS;
}

/* Insert Element e to ith place */
STATUS LinkListInsert(LinkList *l, int ith, ElemType e) {
  Assert(*l, "NOT INIT");
  Assert(ith >= 1, "INVALID INSERTION");
  LinkList ptr = *l;
  int j = 0;
  // find the node before the ith one
  while (ptr && j < ith - 1) {
    ptr = ptr->next;
    Assert(ptr, "INVALID INSERTION");
    j++;
  }

  LinkList node = (LinkList)malloc(sizeof(LNode));
  node->data = e;
  node->next = ptr->next;
  ptr->next = node;

  return SUCCESS;
}

/* Delete the ith node and pass the value to e */
STATUS LinkListDelete(LinkList *l, int ith, ElemType *e) {
  Assert(*l, "NOT INIT");
  Assert(ith >= 1, "INVALID DELETION");
  LinkList ptr = *l;
  int j = 0;
  // find the node before the ith one
  while (ptr && j < ith - 1) {
    ptr = ptr->next;
    Assert(ptr, "INVALID INSERTION");
    j++;
  }
  // node to delete
  LinkList node = ptr->next;
  *e = node->data;
  ptr->next = node->next;

  return SUCCESS;
}

/* Locate the spot of element `e`, passing to array */
STATUS LinkListLocate(LinkList *l, int *ith, ElemType e,
                      int (*compare)(ElemType, ElemType)) {
  Assert(l, "NOT INIT");
  int index = 1;
  int i = 0;
  bool flag = false;
  LinkList ptr = (*l)->next;  // first node
  while (ptr) {
    if (compare(ptr->data, e)) {
      flag = true;
      ith[i] = index;
      i++;
      ptr = ptr->next;
      index++;
      continue;
    }
    ptr = ptr->next;
    index++;
  }
  ith[i] = 20030415;  // mark as end
  if (!flag) {
    LOG("NOT FOUND!");
    return FAILURE;
  }

  return SUCCESS;
}

/* Search for the `ith` element and pass the value to `e` */
STATUS LinkListSearch(LinkList *l, int ith, ElemType *e) {
  Assert(l, "NOT INIT");
  Assert(ith < LinkListLen(l), "INVALID INDEX");
  int i = 1;
  LinkList ptr = (*l)->next;
  // find the ith node
  while (ptr && i < ith) {
    if (!ptr->next) {
      _LOG("INVALID INDEX\n") return FAILURE;
    };
    ptr = ptr->next;
    i++;
  }
  *e = ptr->data;

  return SUCCESS;
}
