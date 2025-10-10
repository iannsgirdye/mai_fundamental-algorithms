#include "../include/pi.h"
#include "../include/utilities.h"
#include <stdlib.h>
#include <math.h>


double _calculatePiSummand(const int n) {
  return pow(-1, n - 1) / (2 * n - 1);
}


double calculatePiUsingRow(const double epsilon) {
  int n = 1;
  double currentValue = _calculatePiSummand(n);
  double nextValue = _calculatePiSummand(++n);
  double sum = currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && n <= MAX_N) {
    currentValue = nextValue;
    nextValue = _calculatePiSummand(++n);
    sum += currentValue;
  }

  return 4 * sum;
}
