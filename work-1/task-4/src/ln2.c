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


double _calculateLn2Summand(const int n) {
  return pow(-1, n - 1) / (double)n;
}


double calculateLn2UsingRow(const double epsilon) {
  int n = 1;

  double currentValue = _calculateLn2Summand(n);
  double nextValue = _calculateLn2Summand(++n);
  double result = currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && n <= MAX_N) {
    currentValue = nextValue;
    nextValue = _calculateLn2Summand(++n);
    result += currentValue;
  }

  return result;
}
