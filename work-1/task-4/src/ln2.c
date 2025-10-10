#include "../include/ln2.h"
#include "../include/utilities.h"
#include <math.h>


double _calculateLn2Function(const int n) {
  return n * (pow(2, 1.0 / n) - 1);
}


double calculateLn2UsingLimit(const double epsilon) {
  int n = 1;

  double prevValue = _calculateLn2Function(n);
  double currentValue = _calculateLn2Function(++n);

  while (fabs(currentValue - prevValue) >= epsilon && n <= MAX_N) {
    prevValue = currentValue;
    currentValue = _calculateLn2Function(++n);
  }

  return currentValue;
}
