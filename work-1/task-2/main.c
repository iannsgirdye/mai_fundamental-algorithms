#include "functions.h"
#include <limits.h>


int main() {
  int T;
  if (get_T(&T) == INVALID_ARGUMENT) {
    return 0;
  }

  int order[T];
  int min_order_number = INT_MAX;
  if (get_order(order, T, &min_order_number) == INVALID_ARGUMENT) {
    return 0;
  }

  int results[T];
  prime_numbers(order, T, results, &min_order_number);

  print_results(results, T);

  return 0;
}
