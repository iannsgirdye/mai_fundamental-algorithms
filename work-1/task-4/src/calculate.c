#include "../include/calculate.h"
#include "../include/utilities.h" 
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


#define X0 -0.5


double limit(double (*function)(const int), const double epsilon) { 
  int n = 1;

  double prevValue = function(n);
  double currentValue = function(++n);

  while (fabs(currentValue - prevValue) >= epsilon && n <= MAX_N) {
    prevValue = currentValue;
    currentValue = function(++n);
  }

  return currentValue;
}


double sqrt2Limit(double (*function)(const double), const double epsilon) {
  double currentValue = X0;
  double nextValue = function(currentValue);

  for (int n = 1; fabs(nextValue - currentValue) >= epsilon && n <= MAX_N; ++n) {
    currentValue = nextValue;
    nextValue = function(currentValue);
  }

  return currentValue;
}


bool _isExponent(const int startN) {
  return startN == 0;
}


double row(double (*function)(const int), const int startN, const double epsilon) {
  int n = startN;
  double result = 0;

  /* function(0) = 1 and function(1) = 1 => 1 - 1 < epsilon
     This is the reason why we start from n = 2 and result += 2 */
  if (_isExponent(startN)) {
    n += 2;
    result += 2;
  }

  double currentValue = function(n);
  double nextValue = function(++n);
  result += currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && n <= MAX_N) {
    currentValue = nextValue;
    nextValue = function(++n);
    result += currentValue;
  }

  return result;
}


double product(double (*function)(const int), const int starnN, const double epsilon) {
  int k = starnN;

  double currentValue = function(k);
  double nextValue = function(++k);
  double product = currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && k <= MAX_N) {
    currentValue = nextValue;
    nextValue = function(++k);
    product *= currentValue;
  }

  return product;
}
