#include "../include/exponent.h"
#include "../include/utilities.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


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


double _calculateExponentSummand(const int n) {
  return 1.0 / factorial(n);
}


double calculateExponentUsingRow(const double epsilon) {
  int n = 1;

  double prevValue = _calculateExponentSummand(n);
  double currentValue = _calculateExponentSummand(++n);
  double result = 2 + currentValue;  // summand = 1 for n = 0 and n = 1 

  while (fabs(currentValue - prevValue) >= epsilon && n <= MAX_N_FOR_FACTORIAL) {
    prevValue = currentValue;
    currentValue = _calculateExponentSummand(++n);
    result += currentValue;
  }

  return result;
}


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
