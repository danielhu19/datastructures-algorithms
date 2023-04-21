/**
 * @file sqstack.c
 * @author DANIEL HU (shady030314@gmail.com)
 * @date 2023-04-08
 */

#include <stack/sqstack.h>

/* Init a NULL stack */
STATUS InitSqStack(SqStack* s) {
  s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
  Assert(s->base, "INIT FAILED");
  s->top = s->base;  // init status
  s->stacksize = STACK_INIT_SIZE;

  return SUCCESS;
}

/* Destroy a given stack */
STATUS DestroySqStack(SqStack* s) {
  free(s->base);
  s->stacksize = 0;
  s->top = NULL;
  s->base = NULL;

  return SUCCESS;
}

/* Set given stack to NULL */
STATUS ClearSqStack(SqStack* s) {
  Assert(s->base, "STACK NOT EXIST");
  s->top = s->base;  // denotes NULL

  return SUCCESS;
}

/* check if SqStack is NULL or not */
bool SqStackEmpty(SqStack* s) { return s->base == s->top; }

/* Get the length of SqStack */
STATUS SqStackLength(SqStack* s) {
  Assert(s->base, "STACK NOT EXIST");  // make sure stack is exist
  return s->top - s->base;
}

/**
 * Return top element to `e`
 * - FAILURE: NULL STACK
 */
STATUS Sq_GetTop(SqStack* s, ElemType* e) {
  Assert(s->base, "STACK NOT EXIST");
  if (s->top == s->base) return FAILURE;
  *e = *(s->top - 1);
  return SUCCESS;
}

/* Push element `e` into the SqStack */
STATUS Sq_Push(SqStack* s, ElemType e) {
  Assert(s->base, "STACK NOT EXIST");
  // increase memory space if stack is FULL
  if (s->top - s->base >= STACK_INIT_SIZE) {
    s->base = (ElemType*)realloc(
        s->base, sizeof(ElemType) * (STACK_INIT_SIZE + STACK_INCRE_SIZE));
    Assert(s->base, "REALLOC FAILED!");
    s->stacksize += STACK_INCRE_SIZE;
  }
  /* assign first, move next */
  *(s->top++) = e;

  return SUCCESS;
}

/**
 * Pop the top element out of SqStack, and pass value to `e`
 * FAILURE: Empty SqStack
 */
STATUS Sq_Pop(SqStack* s, ElemType* e) {
  Assert(s->base, "STACK NOT EXIST");
  if (SqStackEmpty(s)) return FAILURE;
  /* move first, assign next */
  *e = *(--s->top);

  return SUCCESS;
}

void PrintSqStack(SqStack* s) {
  Assert(s->base, "STACK NOT EXIST");
  ElemType* ptr = s->base;
  int len = SqStackLength(s);
  for (int i = 0; i < len; i++) {
    printf("%d ", *ptr);
    ptr++;
  }
  printf("\n");
}