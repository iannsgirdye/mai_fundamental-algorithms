#include "../include/utilities.h"
#include "../include/returnStatus.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MIN_BASE_POW 1
#define MAX_BASE_POW 5

returnStatus getNumber(int *number) {
  long long int tmpNumber;
  scanf("%lld", &tmpNumber);
  if (tmpNumber < 0 || tmpNumber > INT_MAX) {
    return INVALID_NUMBER;
  }
  *number = (int)tmpNumber;
  return OK;
}

returnStatus getBasePow(int *basePow) {
  int tmpBasePow;
  scanf("%d", &tmpBasePow);
  if (tmpBasePow < MIN_BASE_POW || tmpBasePow > MAX_BASE_POW) {
    return INVALID_BASE_POW;
  }
  *basePow = tmpBasePow;
  return OK;
}
