#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>


#define FIBONACCI_CAPACITY 64  // меньше 64 чисел Фибоначчи не превосходит UINT_MAX


returnStatus fibonacci(unsigned int fibonacciValues[], const size_t size) {
  fibonacciValues[0] = 0, fibonacciValues[1] = 1;
  for (size_t i = 2; i != size; ++i) {
    if (fibonacciValues[i] > UINT_MAX - fibonacciValues[i - 1]) {
      return INVALID_ZECKENDORF_NUMBER;
    }
    fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
  }

  return OK;
}


returnStatus flagZr(const char *zeckendorf, unsigned int *number) {
  size_t size = strlen(zeckendorf);

  if (size == 0) {
    return INVALID_ZECKENDORF_NUMBER;
  }
  if (zeckendorf[size - 1] != '1') {
    return INVALID_ZECKENDORF_NUMBER;
  }

  if (strcmp(zeckendorf, "1") == 0) {
    *number = 0;
    return OK;
  }
  if (strcmp(zeckendorf, "11") == 0) {
    *number = 1;
    return OK;
  }

  unsigned int fibonacciValues[FIBONACCI_CAPACITY];
  if (fibonacci(fibonacciValues, size) != OK) {
    return INVALID_ZECKENDORF_NUMBER;
  }

  *number = 0;
  for (size_t i = 0; i != size - 1; ++i) {
    if (zeckendorf[i] == '1') {
      *number += fibonacciValues[i + 1];
    }
  }

  return OK;
}
