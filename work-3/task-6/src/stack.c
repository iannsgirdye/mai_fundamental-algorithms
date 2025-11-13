#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack initStack() {
  Stack s = {.size = 0};
  s.data = (char *)malloc(BUFSIZ);
  s.capacity = (s.data == NULL) ? 0 : BUFSIZ;
  return s;
}

int isEmptyStack(const Stack *s) {
  return s->size == 0;
}

int isFullStack(const Stack *s) {
  return s->size == s->capacity;
}

void pushStack(Stack *s, char c) {
  if (isFullStack(s)) {
    char *tmp = (char *)realloc(s->data, s->capacity * 2);
    if (tmp == NULL) {
      return;
    }
    s->capacity *= 2;
  }
  s->data[s->size] = c;
  ++(s->size);
}

char popStack(Stack *s) {
  if (isEmptyStack(s)) {
    return -1;
  }
  --(s->size);
  return s->data[s->size];
}
