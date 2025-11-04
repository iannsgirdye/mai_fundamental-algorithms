#include "../../include/flags.h"
#include <stdio.h>
#include <stdlib.h>


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


returnStatus _isGoodDigit(const char digit, const int isCapitalize) {
  if (isCapitalize && digit >= 'a' && digit <= 'z') {
    return INVALID_SYSTEM_DIGIT;
  }
  if (!isCapitalize && digit >= 'A' && digit <= 'Z') {
    return INVALID_SYSTEM_DIGIT;
  }
  return OK;
}


returnStatus flagsToTO(const char *numberInSystem, int *system, const int isCapitalize, char *number) {
  if (*system < MIN_SYSTEM || *system > MAX_SYSTEM) {
    *system = 10;
  }
  int _number = 0;

  for (size_t i = 0; numberInSystem[i] != '\0'; ++i) {
    if (_isGoodDigit(numberInSystem[i], isCapitalize) != OK) {
      return INVALID_SYSTEM_DIGIT;
    }
    _number += _charDigit(numberInSystem[i], isCapitalize);
    _number *= *system;
  }
  _number /= *system;
  sprintf(number, "%d", _number);

  return OK;
}
