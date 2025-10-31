#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define BUFFER_SIZE 20


returnStatus checkArray(const size_t size, const void *array) {
  if (size == 0) {
    return INVALID_ARRAY;
  }
  if (array == NULL) {
    return INVALID_ARRAY;
  }
  return OK;
}


returnStatus getSystem(int *system) {
  char *strSystem = (char *)malloc(20);
  scanf("%s", strSystem);

  char *endPtr;
  long int intSystem = strtol(strSystem, &endPtr, 10);
  
  if (*endPtr != '\0') {
    return _errorSystemIsNotDecimalNumber(strSystem);
  }
  if (intSystem < 0 || intSystem > INT_MAX) {
    return _errorInvalidSystem(intSystem);
  }

  *system = intSystem;
  free(strSystem);
  
  return OK;
}


returnStatus getFractions(const size_t size, double fractions[]) {
  if (checkArray(size, fractions) != OK) {
    return _errorInvalidArray("getFraction");
  }

  double decimal;
  for (size_t i = 0; i != size; ++i) {
    scanf("%lf", &decimal);
    if (decimal < 0 || decimal > 1) {
      return _errorInvalidValue(decimal);
    }
    fractions[i] = decimal;
  }

  return OK;
}


returnStatus printResults(const size_t size, const bool results[]) {
  if (checkArray(size, results) != OK) {
    return _errorInvalidArray("printResults");
  }

  for (size_t i = 0; i != size; ++i) {
    printf("%s", results[i] ? "true" : "false");
    printf("%s", (i != size - 1) ? " " : "\n");
  }

  return OK;
}
