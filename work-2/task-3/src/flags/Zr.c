#include "../../include/flags.h"
#include <stdlib.h>
#include <stdio.h>


#define FIBONACCI_CAPACITY 50  // меньше 50 чисел Фибоначчи не превосходит INT_MAX


size_t fibonacci(int fibonacciValues[], int maxNumber) {
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
    fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
    ++i;
  }
  fibonacciValues[i] = fibonacciValues[i - 1] + fibonacciValues[i - 2];
  return i;
}


// 0-й элемент последовательности Фибоначчи не учитывается
void flagZr(int number, char *zeckendorf) {
  int fibonacciValues[FIBONACCI_CAPACITY];
  size_t FibonacciValuesCount = fibonacci(fibonacciValues, number);

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
}
