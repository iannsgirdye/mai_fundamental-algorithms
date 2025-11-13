#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

#define TRUE 1
#define FALSE 0
#define COUNT_OF_BRACKETS_TYPES 4

int chech_brackets(const char *str) {
  if (str == NULL || strlen(str) == 0) {
    return TRUE;
  }

  const size_t strSize = strlen(str);
  const char *openBrackets = "([{<";
  const char *closeBrackets = ")]}>";
  Stack s = initStack();
  char openBracket;
  size_t openBracketIndex;
  
  for (size_t i = 0; i != strSize; ++i) {
    if (strchr(openBrackets, str[i])) {
      pushStack(&s, str[i]);
    } else if (strchr(closeBrackets, str[i])) {
      openBracket = popStack(&s);
      if (openBracket == -1) {
        return FALSE;
      }
      openBracketIndex = strchr(openBrackets, openBracket) - openBrackets;
      if (openBracketIndex >= COUNT_OF_BRACKETS_TYPES || str[i] != closeBrackets[openBracketIndex]) {
        return FALSE; 
      }
    }
  }
  
  return isEmptyStack(&s) ? TRUE : FALSE;
}
