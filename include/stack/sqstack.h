#ifndef SQSTACK_H_
#define SQSTACK_H_

#include <forehead/forehead.h>

#define ElemType int
#define STACK_INIT_SIZE 10
#define STACK_INCRE_SIZE 10

/**
 * 1. base: always points to base of stack
 * - (base == top) -> NULL STACK
 * - (base == NULL) -> STACK NOT EXIST
 * 2. top: always ahead of top element
 */
typedef struct {
  ElemType* base;
  ElemType* top;
  int stacksize;
} SqStack;

STATUS InitSqStack(SqStack* s);
STATUS DestroySqStack(SqStack* s);
STATUS ClearSqStack(SqStack* s);
bool SqStackEmpty(SqStack* s);
STATUS SqStackLength(SqStack* s);
STATUS Sq_Push(SqStack* s, ElemType e);
STATUS Sq_Pop(SqStack* s, ElemType* e);
STATUS Sq_GetTop(SqStack* s, ElemType* e);
void PrintSqStack(SqStack* s);

#endif