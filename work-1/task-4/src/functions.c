#include "../include/functions.h"
#include "../include/utilities.h"
#include <math.h>


double exponentLimitFunction(const int n) {
  return pow(1 + 1.0 / n, n);
}


double exponentRowSummand(const int n) {
  return 1.0 / factorial(n);
}


double exponentEquationDifference(const double x) {
  return log(x) - 1;
}


double ln2LimitFunction(const int n) {
  return n * (pow(2, 1.0 / n) - 1);
}


double ln2RowSummand(const int n) {
  return pow(-1, n - 1) / (double)n;
}


double ln2EquationDifference(const double x, const double exponent) {
  return pow(exponent, x) - 2;
}


double sqrt2LimitFunction(const double prevX) { 
  return prevX - pow(prevX, 2) / 2.0 + 1;
}


double sqrt2ProductMultiplier(const int k) {
  return pow(2, pow(2, -k));
}


double sqrt2EquationDifference(const double x) {
  return pow(x, 2) - 2;
}
