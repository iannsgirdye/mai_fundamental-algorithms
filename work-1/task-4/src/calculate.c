#include "../include/calculate.h"
#include "../include/utilities.h" 
#include <math.h>
#include <stdlib.h>


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
