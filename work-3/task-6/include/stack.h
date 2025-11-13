#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Stack {
  char *data;
  size_t size;
  size_t capacity;
} Stack;

Stack initStack();
int isEmptyStack(const Stack *s);
int isFullStack(const Stack *s);
void pushStack(Stack *s, char c);
char popStack(Stack *s);

#endif
