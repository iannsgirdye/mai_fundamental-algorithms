#include "../include/exponent.h"
#include "../include/utilities.h"
#include <math.h>
#include <stdlib.h>


double _calculateExponentFunction(const int n) {
  return pow(1 + 1.0 / n, n);
}


double calculateExponentUsingLimit(const double epsilon) {
  int n = 1;
  
  double prevValue = _calculateExponentFunction(n);
  double currentValue = _calculateExponentFunction(++n);

  while (fabs(currentValue - prevValue) >= epsilon && n <= MAX_N) {
    prevValue = currentValue;
    currentValue = _calculateExponentFunction(++n);
  }

  return currentValue;
}
