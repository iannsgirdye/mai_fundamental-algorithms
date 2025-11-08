#include "../include/customString.h"
#include "../include/returnStatus.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


returnStatus _stringInit(_string *string) {
  string->size = 0;
  string->capacity = BUFSIZ;
  string->str = (char *)malloc(string->capacity);
  if (string->str == NULL) {
    return INVALID_GET_MEMORY;
  }
  string->str[0] = '\0';
  return OK;
}


int _stringIsFull(_string *string) {
  return string->size == string->capacity;
}


returnStatus _stringRealloc(_string *string) {
  char *tmpStr = (char *)realloc(string->str, string->capacity * 2);
  if (tmpStr == NULL) {
    return INVALID_GET_MEMORY;
  }
  string->str = tmpStr;
  string->capacity *= 2;
  return OK;
}


returnStatus _stringPushCh(_string *string, const char ch) {
  if (string->size + 1 > string->capacity) {
    if (_stringRealloc(string) == INVALID_GET_MEMORY) {
      return INVALID_GET_MEMORY;
    }
  }

  string->str[string->size] = ch;
  ++(string->size);
  string->str[string->size] = '\0';
  return OK;
}


returnStatus _stringPushStr(_string *string, const char *subStr) {
  if (string->size + strlen(subStr) > string->capacity) {
    if (_stringRealloc(string) == INVALID_GET_MEMORY) {
      return INVALID_GET_MEMORY;
    }
  }
  strcat(string->str, subStr);
  return OK;
}
