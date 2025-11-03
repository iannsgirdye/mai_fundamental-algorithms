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


returnStatus flagsCvCV(int number, int system, char *result, const int isCapitalize) {
  if (system < MIN_SYSTEM || system > MAX_SYSTEM) {
    system = 10;
  }

  size_t size = 0;
  const char sign = (number > 0) ? 1 : -1;
  number *= sign;
  if (sign == -1) {
    result[0] = '-';
    size++;
  }

  while (number > 0) {
    result[size] = _digit(number % system, isCapitalize);
    number /= system;
    ++size;
  }
  result[size] = '\0';

  for (size_t i = (sign == 1) ? 0 : 1; i != size / 2; ++i) {
    swap(&result[i], &result[size - 1 - i]);
  }

  return OK;
}
