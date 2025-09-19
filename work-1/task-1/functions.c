#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "utilities.h"
#include "colors.h"


void flag_h(int x) {
  bool have_number = false;
  
  printf(COLOR_BOLD_GREEN "Результат: " COLOR_WHITE);

  for (int n = 1; n <= 100; n++) {
    if (x * n <= 100) {
      printf("%d ", x * n);
      have_number = true;
    } else {
      break;
    }
  }

  if (!have_number) {
    printf("этому числу не кратно ни одно натуральное число в пределах 100 включительно.");
  }

  printf("\n");
}


return_status flag_p(int x) {
  for (int n = 2; n <= x * 0.5; n++) {
    if (x % n == 0) {
      printf(
        COLOR_BOLD_GREEN "Результат: "
        COLOR_WHITE      "это число является составным.\n"
      );
      return OK;
    }
  }

  printf(
    COLOR_BOLD_GREEN "Результат: "
    COLOR_WHITE      "это число является простым.\n"
  );
  return OK;
}


return_status flag_s(int x) {
  const char nums[16] = "0123456789ABCDEF";
  char result[20];

  int numbers_count = 0;
  while (x > 0) {
    int last_number = x % 16;
    result[numbers_count] = nums[last_number];
    x /= 16;
    numbers_count++;
  }

  printf(COLOR_BOLD_GREEN "Результат: " COLOR_WHITE);

  for (int i = numbers_count - 1; i >= 0; i--) {
    printf("%c", result[i]);

    if (i > 0) {
      printf(" ");
    }
  }

  printf("\n");

  return OK;
}


return_status flag_e(int x) {
  if (x > 10) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "число должно быть натуральным и не больше 10 для этого флага.\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  for (int base = 1; base <= 10; base++) {
    unsigned long long int result = base;
    for (int degree = 1; degree <= x; degree++) {
      result *= base;
      printf("%llu", result);
      if (degree < x) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }

  return OK;
}

void flag_a(int x) {
  double result = ((1 + x) / 2.0) * x;
  printf("%ld\n", (long int)result);
}


return_status flag_f(int x) {
  if (x > 20) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "число должно быть натуральным и не больше 20 для этого флага.\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  unsigned long long int result = 1;
  for (int i = 1; i <= x; i++) {
    result *= i;
  }

  printf("%lld\n", result);
  return OK;
}
