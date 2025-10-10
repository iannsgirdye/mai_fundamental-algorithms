#include "../include/utilities.h"


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
