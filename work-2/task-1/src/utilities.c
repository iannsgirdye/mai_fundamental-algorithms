#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define BUFFER_SIZE 20
#define DECIMAL_SYSTEM 10
#define MIN_SYSTEM 2
#define MIN_FRACTION 0
#define MAX_FRACTION 1


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
  char strSystem[BUFFER_SIZE];
  scanf("%s", strSystem);

  char *endPtr;
  long int intSystem = strtol(strSystem, &endPtr, DECIMAL_SYSTEM);
  
  if (*endPtr != '\0') {
    return _errorSystemIsNotDecimalNumber(strSystem);
  }
  if (intSystem < MIN_SYSTEM || intSystem > INT_MAX) {
    return _errorInvalidSystem(intSystem);
  }

  *system = intSystem;
  
  return OK;
}


returnStatus _getFraction(double *fraction) {
  char strFraction[BUFFER_SIZE];
  scanf("%s", strFraction);

  char *endPtr;
  double doubleFraction = strtod(strFraction, &endPtr);

  if (*endPtr != '\0') {
    return _errorDecimalIsNotDecimalFraction(strFraction);
  }
  if (doubleFraction < MIN_FRACTION || doubleFraction > MAX_FRACTION) {
    return _errorInvalidDecimal(doubleFraction);
  }
  
  *fraction = doubleFraction;
  
  return OK;
}


returnStatus getFractions(const size_t size, double fractions[]) {
  if (checkArray(size, fractions) != OK) {
    return _errorInvalidArray("getFraction");
  }

  double decimal;
  for (size_t i = 0; i != size; ++i) {
    if (_getFraction(&decimal) != OK) {
      return !OK;
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
