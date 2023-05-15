#include <queue/linkqueue.h>
#include <tree/bitree.h>

void visit(ElemType e) { printf("%c ", e); }

/* traverse by NLR via Recursion */
STATUS preorderTraverse(BiTree T, void (*visit)(ElemType e)) {
  if (T) {
    visit(T->data);
    preorderTraverse(T->lchild, visit);
    preorderTraverse(T->rchild, visit);
  }
  return SUCCESS;
}

/* traverse by LNR via Recursion */
STATUS inorderTraverse(BiTree T, void (*visit)(ElemType e)) {
  if (T) {
    inorderTraverse(T->lchild, visit);
    visit(T->data);
    inorderTraverse(T->rchild, visit);
  }
  return SUCCESS;
}

/* traverse by LRN via Recursion */
STATUS postorderTraverse(BiTree T, void (*visit)(ElemType e)) {
  if (T) {
    postorderTraverse(T->lchild, visit);
    postorderTraverse(T->rchild, visit);
    visit(T->data);
  }
  return SUCCESS;
}

/* Create a Binary Tree in Pre-Order */
STATUS createBiTree(BiTree *root) {
  ElemType data;
  scanf("%c", &data);
  if (data == '#') {
    *root = NULL;
  } else {
    *root = (BiTree)malloc(sizeof(BiTreeNode));
    Assert(*root != NULL, "malloc failed");
    (*root)->data = data;
    createBiTree(&(*root)->lchild);
    createBiTree(&(*root)->rchild);
  }

  return SUCCESS;
}

/* Return the depth of given Tree via Recursion */
int BiTreeDepth(BiTree *T) {
  // null tree
  if (*T == NULL) {
    return 0;
  }
  int llen, rlen;
  if ((*T)->lchild)
    llen = BiTreeDepth(&(*T)->lchild);
  else
    llen = 0;

  if ((*T)->rchild)
    rlen = BiTreeDepth(&(*T)->rchild);
  else
    rlen = 0;

  return llen > rlen ? llen + 1 : rlen + 1;
}

void InThread(ThreadTree T, ThreadTree pre) {
  if (T) {
    InThread(T->lchild, pre);
    if (!T->lchild) {
      T->lchild = pre;
      T->ltag = 1;
    }
    if (pre && !pre->rchild) {
      pre->rchild = T;
      pre->rtag = 1;
    }
    pre = T;
    InThread(T->rchild, pre);
  }
}

void PreThread(ThreadTree T, ThreadTree pre) {
  if (T) {
    if (!T->lchild) {
      T->lchild = pre;
      T->ltag = 1;
    }
    if (pre && !pre->rchild) {
      pre->rchild = T;
      pre->rtag = 1;
    }
    pre = T;
    /* Note: ltag不是前驱线索 */
    if (T->ltag == 0) {
      PreThread(T->lchild, pre);
    }
    PreThread(T->rchild, pre);
  }
}

void PostThread(ThreadTree T, ThreadTree pre) {
  if (T) {
    PostThread(T->lchild, pre);
    PostThread(T->rchild, pre);
    if (!T->lchild) {
      T->lchild = pre;
      T->ltag = 1;
    }
    if (pre && !pre->rchild) {
      pre->rchild = T;
      pre->rtag = 1;
    }
    pre = T;
  }
}

STATUS CreateInThread(ThreadTree T) {
  Assert(T, "null tree");
  ThreadTree pre = NULL;
  InThread(T, pre);
  pre->rchild = NULL;  // must be null
  pre->rtag = 1;

  return SUCCESS;
}

STATUS CreatePreThread(ThreadTree T) {
  Assert(T, "null tree");
  ThreadTree pre = NULL;
  PreThread(T, pre);
  if (pre->rchild == NULL) pre->rtag = 1;

  return SUCCESS;
}

STATUS CreatePostThread(ThreadTree T) {
  Assert(T, "null tree");
  ThreadTree pre = NULL;
  PostThread(T, pre);
  if (pre->rchild == NULL) pre->rtag = 1;

  return SUCCESS;
}
