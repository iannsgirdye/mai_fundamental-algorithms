#include "../include/calculate.h"
#include "../include/utilities.h" 
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define X0 -0.5
#define STRINGS_ARE_EQUAL 0

#define EXPONENT_START_RESULT 2
#define DEFAULT_START_RESULT 0


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


int _defineStarnN(const char *type) {
  if (_typeIsPi(type) || _typeIsLn2(type)) {
    return 1;
  } 
  
  return 2;
}


double row(const char *type, double (*function)(const int), const double epsilon) {
  int n = _defineStarnN(type);
  /* function(0) = 1 and function(1) = 1 => 1 - 1 < epsilon
     This is the reason why we start from n = 2 and result += 2 */
  double result = _typeIsExponent(type) ? EXPONENT_START_RESULT : DEFAULT_START_RESULT;

  double currentValue = function(n);
  double nextValue = function(++n);
  result += currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && n <= MAX_N) {
    currentValue = nextValue;
    nextValue = function(++n);
    result += currentValue;
  }

  return result;
}


double product(const char *type, double (*function)(const int), const double epsilon) {
  int k = _defineStarnN(type);

  double currentValue = function(k);
  double nextValue = function(++k);
  double product = currentValue;

  while (fabs(nextValue - currentValue) >= epsilon && k <= MAX_N) {
    currentValue = nextValue;
    nextValue = function(++k);
    product *= currentValue;
  }

  return product;
}


void _initBorderValues(const char *type, double *leftValue, double *rightValue) {
  if (strcmp(type, "exponent") == STRINGS_ARE_EQUAL) {
    *leftValue = 2.5;
    *rightValue = 3.0;
  } else if (strcmp(type, "ln2") == STRINGS_ARE_EQUAL) {
    *leftValue = 0.5;
    *rightValue = 1.0;
  } else if (strcmp(type, "sqrt2") == STRINGS_ARE_EQUAL) {
    *leftValue = 1.2;
    *rightValue = 1.7;
  }
}


double equation(const char *type, double (*function)(const double), const double epsilon) {
  double leftValue, rightValue;
  _initBorderValues(type, &leftValue, &rightValue);

  double middleValue = _middleValue(leftValue, rightValue);
  double exponentDifference = function(middleValue);

  for (int n = 0; fabs(exponentDifference) >= epsilon && n < MAX_N; ++n) {
    if (exponentDifference < 0) {
      leftValue = middleValue;
    } else {
      rightValue = middleValue;
    }
    
    middleValue = _middleValue(leftValue, rightValue);
    exponentDifference = function(middleValue);
  }

  return middleValue;
}


double equationLn2(
  double (*function)(const double, const double),
  const double exponent,
  const double epsilon
) {
  double leftValue, rightValue;
  _initBorderValues("ln2", &leftValue, &rightValue);

  double middleValue = _middleValue(leftValue, rightValue);
  double exponentDifference = function(middleValue, exponent);

  for (int n = 0; fabs(exponentDifference) >= epsilon && n < MAX_N; ++n) {
    if (exponentDifference < 0) {
      leftValue = middleValue;
    } else {
      rightValue = middleValue;
    }
    
    middleValue = _middleValue(leftValue, rightValue);
    exponentDifference = function(middleValue, exponent);
  }

  return middleValue;
}
