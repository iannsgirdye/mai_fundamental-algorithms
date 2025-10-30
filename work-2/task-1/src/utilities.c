#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>


returnStatus _checkArray(const size_t size, const void *array) {
  if (size == 0) {
    return INVALID_ARRAY;
  }
  if (array == NULL) {
    return INVALID_ARRAY;
  }
  return OK;
}


returnStatus getFractions(const size_t size, double fractions[]) {
  if (_checkArray(size, fractions) != OK) {
    return _errorInvalidArray();
  }

  for (size_t i = 0; i != size; ++i) {
    scanf("%lf", &fractions[i]);
  }

  return OK;
}
