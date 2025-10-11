#include "../include/sqrt2.h"
#include "../include/utilities.h"
#include <stdlib.h>
#include <math.h>


double _sqrt2Difference(const double x) {
  return pow(x, 2) - 2;
}


double calculateSqrt2UsingEquation(const double epsilon) {
  double leftValue = 1.3;
  double rightValue = 1.6;
  double middleValue = _middleValue(leftValue, rightValue);
  double sqrt2Difference = _sqrt2Difference(middleValue);

  for (int n = 0; fabs(sqrt2Difference) >= epsilon && n <= MAX_N; ++n) {
    if (sqrt2Difference < 0) {
      leftValue = middleValue;
    } else {
      rightValue = middleValue;
    }

    middleValue = _middleValue(leftValue, rightValue);
    sqrt2Difference = _sqrt2Difference(middleValue);
  }

  return middleValue;
}
