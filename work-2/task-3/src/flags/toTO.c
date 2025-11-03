#include "../../include/flags.h"
#include <stdlib.h>
#include <stdio.h>


#define MIN_SYSTEM 2
#define MAX_SYSTEM 36


char _charDigit(const char digit, const int isCapitalize) {
  if (digit >= '0' && digit <= '9') {
    return digit - '0';
  }
  if (isCapitalize) {
    return digit - 'A' + 10 ;
  }
  return digit - 'a' + 10;
}


int _isGoodDigit(const char digit, const int isCapitalize) {
  if (isCapitalize && digit >= 'a' && digit <= 'z') {
    return 0;
  }
  if (!isCapitalize && digit >= 'A' && digit <= 'Z') {
    return 0;
  }
  return 1;
}


returnStatus flagsToTO(const char number[], const int system, int *result, const int isCapitalize) {
  if (system < MIN_SYSTEM || system > MAX_SYSTEM) {
    return INVALID_SYSTEM;
  }

  for (size_t i = 0; number[i] != '\0'; ++i) {
    if (!_isGoodDigit(number[i], isCapitalize)) {
      return INVALID_SYSTEM_DIGIT;
    }
    *result += _charDigit(number[i], isCapitalize);
    *result *= system;
  }
  *result /= system;

  return OK;
}
