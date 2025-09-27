#include "../include/search.h"
#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>


returnStatus _convertNumber(struct number *_number, const int system) {
  int convertedNumber = 0;
  char strDigit;
  int sign = 1;

  for (size_t i = 0; _number->strValue[i] != '\0'; ++i) {
    strDigit = _number->strValue[i];
    
    if (i == 0 && strDigit == '-') {
      sign = -1;
      continue;
    }

    convertedNumber *= system;
    if (isdigit(strDigit)) {
      convertedNumber += strDigit - '0';
    } else if (isupper(strDigit)) {
      convertedNumber += strDigit - 'A' + 10;
    } else if (islower(strDigit)) {
      return _errorSmallAlpha();
    } else {
      return _errorInvalidNumber();
    }
  }

  _number->intValue = sign * convertedNumber;

  return OK;
}


returnStatus _toNSystem(char convertedStrNumber[], int number, const int system) {
  int digit;
  size_t i;

  int sign = (number > 0) ? 1 : -1;
  number *= sign;

  for (i = 0; number > 0; ++i) {
    if (i == 0 && sign == -1) {
      convertedStrNumber[i] = '-';
      continue;
    }

    digit = number % system;
    if (digit < 10) {
      convertedStrNumber[i] = digit + '0';      
    } else {
      convertedStrNumber[i] = digit + 'A' - 10;
    }
    
    number /= system;
  }

  char tmpDigit;
  for (size_t j = 0; j != i / 2; ++j) {
    tmpDigit = convertedStrNumber[j];
    convertedStrNumber[j] = convertedStrNumber[i - j - 1];
    convertedStrNumber[i - j - 1] = tmpDigit;
  }

  convertedStrNumber[i] = '\0';
  return OK;
}


returnStatus _compareNumbers(struct number *_number, struct number *maxNumber) {
  if (_number->intValue > maxNumber->intValue) { 
    strcpy(maxNumber->strValue, _number->strValue);
    maxNumber->intValue = _number->intValue;
  }

  return OK;
}


returnStatus searchMaxNumber(struct number *maxNumber, const int system) {
  const char *endStr = "Stop";
  struct number _number;

  scanf("%s", _number.strValue);
  while (strcmp(_number.strValue, endStr) != 0) {
    if (_convertNumber(&_number, system) != OK) {
      return INVALID_VALUE;
    }
    if (_compareNumbers(&_number, maxNumber) != OK) {
      return INVALID_VALUE;
    } 
    scanf("%s", _number.strValue);
  }

  return OK;
}


returnStatus printMaxNumber(struct number *maxNumber) {
  printf("%s", maxNumber->strValue);
  
  char convertedStrNumber[33];

  for (int system = 9; system <= 36; system += 9) {
    _toNSystem(convertedStrNumber, maxNumber->intValue, system);
    printf(" %s", convertedStrNumber);
  }

  printf("\n");
  
  return OK;
}
