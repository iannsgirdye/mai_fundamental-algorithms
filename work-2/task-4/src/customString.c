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


int _stringWillOverflow(_string *string, const size_t size) {
  return string->size + size > string->capacity;
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
  if (_stringWillOverflow(string, 1)) {
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
  if (_stringWillOverflow(string, strlen(subStr))) {
    if (_stringRealloc(string) == INVALID_GET_MEMORY) {
      return INVALID_GET_MEMORY;
    }
  }
  strcat(string->str, subStr);
  return OK;
}
