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


returnStatus flagsCvCV(int number, int *system, const int isCapitalize, char *numberInSystem) {
  if (*system < MIN_SYSTEM || *system > MAX_SYSTEM) {
    *system = 10;
  }

  if (number == 0) {
    numberInSystem[0] = '0', numberInSystem[1] = '\0';
    return OK;
  }

  size_t size = 0;
  const char sign = (number > 0) ? 1 : -1;
  number *= sign;
  if (sign == -1) {
    numberInSystem[0] = '-';
    ++size;
  }

  while (number > 0) {
    numberInSystem[size] = _digit(number % *system, isCapitalize);
    number /= *system;
    ++size;
  }
  numberInSystem[size] = '\0';

  for (size_t i = (sign == 1) ? 0 : 1; i != size / 2; ++i) {
    swap(&numberInSystem[i], &numberInSystem[size - 1 - i]);
  }

  return OK;
}
