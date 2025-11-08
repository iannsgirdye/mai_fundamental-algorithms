#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H


#include <stdlib.h>
#include "./returnStatus.h"


typedef struct {
  char *str;
  size_t size;
  size_t capacity;
} _string;


returnStatus _stringInit(_string *string);
int _stringIsFull(_string *string);
returnStatus _stringPushCh(_string *string, const char ch);
returnStatus _stringPushStr(_string *string, const char *str);


#endif
