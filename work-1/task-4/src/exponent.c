#include "../include/exponent.h"
#include "../include/utilities.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


double _calculateExponentDifference(const double x) {
  return log(x) - 1;
}


double calculateExponentUsingEquation(const double epsilon) {
  double leftValue = 2.5;
  double rightValue = 3.0;
  double middleValue = _middleValue(leftValue, rightValue);
  double exponentDifference = _calculateExponentDifference(middleValue);

  for (int n = 0; fabs(exponentDifference) >= epsilon && n < MAX_N; ++n) {
    if (exponentDifference < 0) {
      leftValue = middleValue;
    } else {
      rightValue = middleValue;
    }
    
    middleValue = _middleValue(leftValue, rightValue);
    exponentDifference = _calculateExponentDifference(middleValue);
  }

  return middleValue;
}
