#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define FIBONACCI_CAPACITY 50  // меньше 50 чисел Фибоначчи не превосходит INT_MAX


returnStatus fibonacci(unsigned int fibonacciValues[], unsigned int maxNumber, size_t *size) {
  if (maxNumber == 0) {
    return 0;
  }
  if (maxNumber == 1) {
    return 1;
  }

  size_t i = 2;
  fibonacciValues[0] = 0;
  fibonacciValues[1] = 1;
  while (fibonacciValues[i - 1] <= maxNumber - fibonacciValues[i - 2]) {
    if (fibonacciValues[i] > INT_MAX - fibonacciValues[i - 1]) {
      return INVALID_ZECKENDORF_NUMBER;
    }
    fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
    ++i;
  }
  fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
  
  *size = i;
  return OK;
}


returnStatus flagZr(unsigned int number, char *zeckendorf) {
  unsigned int fibonacciValues[FIBONACCI_CAPACITY];
  size_t FibonacciValuesCount;
  if (fibonacci(fibonacciValues, number, FibonacciValuesCount) != OK) {
    return INVALID_ZECKENDORF_NUMBER;
  }

  // 0-й элемент последовательности Фибоначчи не учитывается
  zeckendorf[FibonacciValuesCount] = '\0';
  zeckendorf[FibonacciValuesCount - 1] = '1';
  for (size_t i = FibonacciValuesCount - 1; i != 0; --i) {
    if (number >= fibonacciValues[i]) {
      number -= fibonacciValues[i];
      zeckendorf[i - 1] = '1';
    } else {
      zeckendorf[i - 1] = '0';
    }
  }
  
  return OK;
}
