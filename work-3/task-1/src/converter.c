#include "../include/converter.h"
#include "../include/returnStatus.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

char charDigit(int digit) {
  if (0 <= digit && digit <= 9) {
    return digit + '0';
  }
  return digit + 10 + 'A';
}

returnStatus convertNumber(int number, int basePow, char *convertedNumber) {
  if (convertedNumber == NULL) {
    return INVALID_BUFFER;
  }

  convertedNumber[0] = '\0';
  if (number < 2) {
    convertedNumber[0] = charDigit(number);
    convertedNumber[1] = '\0';
    return OK;
  }

  int base = (int)pow(2, basePow);
  for (size_t i = 0; number > 0; ++i) {
    convertedNumber[i] = charDigit(number & (base - 1));
    convertedNumber[i + 1] = '\0';
    number = number >> basePow;
  }

  char tmp;
  size_t size = strlen(convertedNumber);
  for (size_t i = size - 1; i != size / 2; --i) {
    tmp = convertedNumber[i];
    convertedNumber[i] = convertedNumber[size - 1 - i];
    convertedNumber[size - 1 - i] = tmp;
  }

  return OK;
}
