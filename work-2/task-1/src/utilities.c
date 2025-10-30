#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>


returnStatus checkArray(const size_t size, const void *array) {
  if (size == 0) {
    return INVALID_ARRAY;
  }
  if (array == NULL) {
    return INVALID_ARRAY;
  }
  return OK;
}


returnStatus getFractions(const size_t size, double fractions[]) {
  if (checkArray(size, fractions) != OK) {
    return _errorInvalidArray();
  }

  for (size_t i = 0; i != size; ++i) {
    scanf("%lf", &fractions[i]);
  }

  return OK;
}


returnStatus printResults(const size_t size, const bool results[]) {
  if (checkArray(size, results) != OK) {
    return _errorInvalidArray();
  }

  for (size_t i = 0; i != size; ++i) {
    printf("%s", results[i] ? "true" : "false");
    printf("%s", (i != size - 1) ? " " : "\n");
  }

  return OK;
}
