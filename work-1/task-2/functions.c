#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "functions.h"
#include "colors.h"


#define MAX_LEN_NUMBER 10
#define min(a, b) (a < b) ? a : b


return_status get_number(int *number) {
  char str_number[MAX_LEN_NUMBER + 1] = "";
  fgets(str_number, sizeof(str_number), stdin);
  
  str_number[strcspn(str_number, "\n")] = '\0';

  char* endptr;
  long int converted_number = strtol(str_number, &endptr, 10);

  if (*endptr != '\0') {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "некорректный формат натурального числа.\n"
    );
    return INVALID_ARGUMENT;
  }

  if (converted_number < 1 || converted_number > INT_MAX) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "число должно быть натуральным и не превышать %d.\n",
      INT_MAX
    );
    return INVALID_ARGUMENT;
  }

  *number = (int)converted_number;
  return OK;
}


return_status get_T(int *T) {
  printf(COLOR_BOLD_CYAN "Введите количество запросов: " COLOR_WHITE);
  return get_number(T);
}


return_status get_order(int order[], int T, int* min_order_number) {
  printf(
    COLOR_BOLD_CYAN "Введите порядковые номера простых чисел по-одному на каждой строке:\n"
    COLOR_WHITE
  );

  for (int i = 0; i < T; i++) {
    if (get_number(&order[i]) == INVALID_ARGUMENT) {
      return INVALID_ARGUMENT;
    }

    *min_order_number = min(*min_order_number, order[i]);
  }
  
  return OK;
}


bool is_prime(int n) {
  for (int d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return false;
    }
  }

  return true;
}


void prime_numbers(int order[], int T, int results[], int* min_order_number) {
  int current_order_number = 0;
  int found_numbers = 0;
  int future_min_order_number = *min_order_number;

  for (int n = 2; found_numbers < T; n++) {
    if (is_prime(n)) {
      current_order_number++;
      
      if (current_order_number == *min_order_number) {
        for (int i = 0; i < T; i++) {
          if (order[i] == current_order_number) {
            order[i] = -1;
            results[i] = n;
            found_numbers++;
          } else if (order[i] != -1) {
            if (future_min_order_number == *min_order_number) {
              future_min_order_number = order[i];
            } else {
              future_min_order_number = min(future_min_order_number, order[i]);
            }
          }
        }

        *min_order_number = future_min_order_number;
      }
    }
  }
}


void print_results(int results[], int T) {
  printf(COLOR_BOLD_GREEN "Результат:\n" COLOR_WHITE);

  for (int i = 0; i < T; i++) {
    printf("%d\n", results[i]);
  }
}
