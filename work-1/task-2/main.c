#include "functions.h"
#include <stdio.h>


int main() {
  int T;
  if (get_T(&T) == INVALID_ARGUMENT) {
    return 0;
  }

  int order[T];
  if (get_order(order, T) == INVALID_ARGUMENT) {
    return 0;
  }

  int results[T];
  prime_numbers(order, T, results);

  print_results(results, T);

  return 0;
}
