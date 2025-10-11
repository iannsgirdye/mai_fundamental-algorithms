#include "../include/ln2.h"
#include "../include/utilities.h"
#include <math.h>


double _ln2Difference(const double x, const double exponent) {
  return pow(exponent, x) - 2;
}


double calculateLn2UsingEquation(const double epsilon, const double exponent) {
  double leftValue = 0.5;
  double rightValue = 0.9;
  double middleValue = _middleValue(leftValue, rightValue);
  double ln2Difference = _ln2Difference(middleValue, exponent);

  for (int n = 0; fabs(ln2Difference) >= epsilon && n <= MAX_N; ++n) {
    if (ln2Difference < 0) {
      leftValue = middleValue;
    } else {
      rightValue = middleValue;
    }

    middleValue = _middleValue(leftValue, rightValue);
    ln2Difference = _ln2Difference(middleValue, exponent);
  }

  return middleValue;
}
