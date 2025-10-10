#include "../include/sqrt2.h"
#include "../include/utilities.h"
#include <stdlib.h>
#include <math.h>


#define X0 -0.5


double _calculateSqrt2Function(const double prevX) {  
  return prevX - pow(prevX, 2) / 2.0 + 1;
}


double calculateSqrt2UsingLimit(const double epsilon) {
  double currentValue = X0;
  double nextValue = _calculateSqrt2Function(currentValue);

  for (int n = 1; fabs(nextValue - currentValue) >= epsilon && n <= MAX_N; ++n) {
    currentValue = nextValue;
    nextValue = _calculateSqrt2Function(currentValue);
  }

  return currentValue;
}
