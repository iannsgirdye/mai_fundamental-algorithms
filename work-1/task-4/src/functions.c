#include "../include/functions.h"
#include <math.h>


double exponentLimitFunction(const int n) {
  return pow(1 + 1.0 / n, n);
}


double ln2LimitFunction(const int n) {
  return n * (pow(2, 1.0 / n) - 1);
}


double sqrt2LimitFunction(const double prevX) { 
  return prevX - pow(prevX, 2) / 2.0 + 1;
}


