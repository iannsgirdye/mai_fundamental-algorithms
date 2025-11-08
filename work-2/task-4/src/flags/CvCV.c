#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <string.h>


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


returnStatus _checkDigit(const char digit, const int isCapitalize) {
  if (isCapitalize && digit >= 'a' && digit <= 'z') {
    return INVALID_SYSTEM_DIGIT;
  }
  if (!isCapitalize && digit >= 'A' && digit <= 'Z') {
    return INVALID_SYSTEM_DIGIT;
  }
  return OK;
}


returnStatus flagsCvCV(const char *numberInSystem, int *system, const int isCapitalize, int *number) {
  if (*system < MIN_SYSTEM || *system > MAX_SYSTEM) {
    *system = 10;
  }
  int result = 0;

  const size_t size = strlen(numberInSystem);
  for (size_t i = 0; i != size; ++i) {
    if (_checkDigit(numberInSystem[i], isCapitalize) != OK) {
      return INVALID_SYSTEM_DIGIT;
    }
    result += _charDigit(numberInSystem[i], isCapitalize);
    result *= *system;
  }
  result /= *system;

  *number = result;
  return OK;
}
