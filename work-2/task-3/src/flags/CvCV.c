#include "../../include/flags.h"
#include <stdlib.h>


#define MIN_SYSTEM 2
#define MAX_SYSTEM 36


void swap(char *first, char *second) {
  char tmp = *first;
  *first = *second;
  *second = tmp;
}


char _digit(const char digit, const int isCapitalize) {
  if (digit < 10) {
    return digit + '0';
  }
  if (isCapitalize) {
    return digit - 10 + 'A';
  }
  return digit - 10 + 'a';
}


returnStatus _reallocResult(char **_result, size_t *capacity) {
  *capacity *= 2;
  
  char *_tmpResult = (char *)realloc(*_result, *capacity);
  if (_tmpResult == NULL) {
    return INVALID_GET_MEMORY;
  }
  *_result = _tmpResult;

  return OK;
}


returnStatus flagsCvCV(int number, const int system, char **result, const int isCapitalize) {
  if (system < MIN_SYSTEM || system > MAX_SYSTEM) {
    return INVALID_SYSTEM;
  }

  size_t size = 0, capacity = 16;
  char *_result = (char *)malloc(capacity);
  if (result == NULL) {
    return INVALID_GET_MEMORY;
  }

  const char sign = (number > 0) ? 1 : -1;
  number *= sign;
  if (sign == -1) {
    _result[0] = '-';
    size++;
  }

  while (number > 0) {
    if (size == capacity && _reallocResult(&_result, &capacity) != OK) {
      return INVALID_GET_MEMORY;
    }
    _result[size] = _digit(number % system, isCapitalize);
    number /= system;
    ++size;
  }
  _result[size] = '\0';

  for (size_t i = (sign == 1) ? 0 : 1; i != size / 2; ++i) {
    swap(&_result[i], &_result[size - 1 - i]);
  }

  *result = _result;

  return OK;
}
