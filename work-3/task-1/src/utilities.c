#include "../include/utilities.h"
#include "../include/returnStatus.h"
#include <stdio.h>
#include <math.h>

#define MIN_BASE_POW 1
#define MAX_BASE_POW 5

returnStatus getBasePow(int *basePow) {
  int tmpBasePow;
  scanf("%d", &tmpBasePow);
  if (tmpBasePow < MIN_BASE_POW || tmpBasePow > MAX_BASE_POW) {
    return INVALID_BASE_POW;
  }
  *basePow = tmpBasePow;
  return OK;
}
