#include "../include/utilities.h"


unsigned long long factorial(const int n) {
  unsigned long long sum = 1;

  for (int i = 2; i != n + 1; ++i) {
    sum *= i;
  }

  return sum;
}


