#include "../include/utilities.h"
#include <stdbool.h>
#include <string.h>


#define STRINGS_ARE_EQUAL 0


bool _typeIsExponent(const char *type) {
  return strcmp(type, "exponent") == STRINGS_ARE_EQUAL;
}


bool _typeIsPi(const char *type) {
  return strcmp(type, "pi") == STRINGS_ARE_EQUAL;
}


bool _typeIsLn2(const char *type) {
  return strcmp(type, "ln2") == STRINGS_ARE_EQUAL;
}


bool _typeIsSqrt2(const char *type) {
  return strcmp(type, "sqrt2") == STRINGS_ARE_EQUAL;
}


bool _typeIsGamma(const char *type) {
  return strcmp(type, "gamma") == STRINGS_ARE_EQUAL;
}


unsigned long long factorial(const int n) {
  unsigned long long sum = 1;

  for (int i = 2; i <= n; ++i) {
    sum *= i;
  }

  return sum;
}


double _middleValue(const double leftValue, const double rightValue) {
  return rightValue - (rightValue - leftValue) / 2;
}


double _combinations(const int k, const int m) {
  return (double)factorial(k) / (factorial(m) * factorial(k - m));
}
