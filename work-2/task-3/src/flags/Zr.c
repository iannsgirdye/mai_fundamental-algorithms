#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <limits.h>


#define FIBONACCI_CAPACITY 64  // меньше 64 чисел Фибоначчи не превосходит UINT_MAX


returnStatus fibonacci(unsigned int fibonacciValues[], unsigned int maxNumber, size_t *size) {
  if (maxNumber == 0) {
    *size = 0;
    return OK;
  }
  if (maxNumber == 1) {
    *size = 1;
    return OK;
  }

  size_t i = 1;
  fibonacciValues[0] = 0, fibonacciValues[1] = 1;
  while (fibonacciValues[i] <= maxNumber) {
    if (fibonacciValues[i] > UINT_MAX - fibonacciValues[i - 1]) {
      return INVALID_ZECKENDORF_NUMBER;
    }
    ++i;
    fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
  }
  
  *size = i;
  return OK;
}


returnStatus flagZr(unsigned int number, char *zeckendorf) {
  if (number == 0) {
    zeckendorf[0] = '1', zeckendorf[1] = '\0';
    return OK;
  } else if (number == 1) {
    zeckendorf[0] = '1', zeckendorf[1] = '1', zeckendorf[2] = '\0';
    return OK;
  }

  unsigned int fibonacciValues[FIBONACCI_CAPACITY];
  size_t fibonacciSize;
  if (fibonacci(fibonacciValues, number, &fibonacciSize) != OK) {
    return INVALID_ZECKENDORF_NUMBER;
  }

  zeckendorf[fibonacciSize] = '\0';
  zeckendorf[fibonacciSize - 1] = '1';
  for (size_t i = fibonacciSize - 1; i != 0; --i) {
    if (number >= fibonacciValues[i]) {
      number -= fibonacciValues[i];
      zeckendorf[i - 1] = '1';
    } else {
      zeckendorf[i - 1] = '0';
    }
  }

  return OK;
}
