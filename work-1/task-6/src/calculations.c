#include "../include/calculations.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define EPSILON 0.000001


double _functionA(double x) {
  if (x < EPSILON) {
    x = EPSILON;
  }
  return log(1 + x) / x;
}


double _functionB(double x) {
  return exp(-pow(x, 2) / 2);
}


double _functionC(double x) {
  if (fabs(1 - x) < EPSILON) {
    x -= EPSILON;
  }
  return log(1 / (1 - x));
}


double _functionD(double x) {
  if (x < EPSILON) {
    x = EPSILON;
  }
  return pow(x, x);
}


double _trapezoidMethod(const int n, double function(double)) {
  double a = 0.0;
  double b = 1.0;

  double I, h;
  
  h = (b - a) / n;
  I = (function(a) + function(b)) / 2;
  for (int i = 1; i != n - 1; ++i) {
    I += function((double)i / n);
  }
  I *= h;
  
  return I;
}


double _calculateIntegral(const double epsilon, double function(double)) {
  int n = 10;
  double I1, I2;
  double result = epsilon + 1;
  
  I1 = _trapezoidMethod(n, function);
  n *= 2;
  I2 = _trapezoidMethod(n, function);
  result = I2 - I1;

  while (result >= epsilon) {
    I1 = I2;
    n *= 2;
    I2 = _trapezoidMethod(n, function);
    result = I2 - I1;
  }

  return I2;
}


void calculateIntegrals(const double epsilon) {
  double (*functions[4])(double) = {_functionA, _functionB, _functionC, _functionD};
  
  for (size_t i = 0; i != 4; ++i) {
    printf("%lf\n", _calculateIntegral(epsilon, functions[i]));
  }
}
