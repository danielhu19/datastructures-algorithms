#ifndef _TREE_H_
#define _TREE_H_

#include <forehead/include.h>

#define MAX_TREE_SIZE 100
#define ElemType int

/* 双亲表示法 */
typedef struct {
  ElemType data;
  int parent;
} PTNode;

typedef struct {
  PTNode nodes[MAX_TREE_SIZE];
  int n;  // numbers of nodes
} PTree;

/* 孩子表示法 */
struct CNode {
  ElemType child;  // location in ARRAY
  struct CNode* next;
};

typedef struct CBox {
  ElemType data;
  struct CNode* firstChild;
} CBox;

typedef struct CTree {
  CBox nodes[MAX_TREE_SIZE];
  int n;  // numbers of nodes
  int r;  // location of root
} CTree;

/* 孩子兄弟表示法 */
typedef struct CSNode {
  ElemType data;
  struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;

#endif