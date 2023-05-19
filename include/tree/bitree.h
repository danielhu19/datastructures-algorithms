#ifndef _BITREE_H_
#define _BITREE_H_

#include <forehead/forehead.h>

#define ElemType char

typedef struct BiTreeNode {
  ElemType data;
  struct BiTreeNode *lchild;
  struct BiTreeNode *rchild;
} BiTreeNode, *BiTree;

typedef struct ThreadNode {
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(ElemType e);
STATUS preorderTraverse(BiTree T, void (*visit)(ElemType e));
STATUS inorderTraverse(BiTree T, void (*visit)(ElemType e));
STATUS postorderTraverse(BiTree T, void (*visit)(ElemType e));

STATUS createBiTree(BiTree *T);

#endif