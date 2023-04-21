#include <stack/sqstack.h>
char leftOf(char c);

// https://leetcode.cn/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
bool detectBracket(char* s, int length) {
  if (length % 2 == 1) return false;
  char e = 0;
  SqStack stack;
  InitSqStack(&stack);
  for (int i = 0; i < length; i++) {
    if (*s == '{' || *s == '(' || *s == '[') Sq_Push(&stack, *s);
    Sq_GetTop(&stack, &e);
    if (!SqStackEmpty(&stack) && leftOf(*s) == e) {
      Sq_Pop(&stack, &e);
    } else
      return false;
  }
  return SqStackEmpty(&stack);
}

char leftOf(char c) {
  if (c == '(') return ')';
  if (c == '{') return '}';
  if (c == '[') return ']';
}
