#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "utilities.h"
#include "functions.h"
#include "colors.h"


void flag_q(int argc, char* argv[]) {
  double numbers[4];
  convert_all_double_numbers(argc, argv, numbers);

  double epsilon = numbers[0];

  double results[12];
  bool repeated_results[12] = {false};
  int found_results = 0;

  for (int i = 1; i < 4; i++) {
    double a = numbers[i];
    for (int j = 1; j < 4; j++) {
      if (i != j) {
        double b = numbers[j];
        for (int k = 1; k < 4; k++) {
          if (i != k && j != k) {
            double c = numbers[k];
            
            double D = b * b - 4 * a * c;
            if (D >= 0) {
              results[found_results] = (-b + sqrt(D)) / (2 * a);
              found_results++;
              results[found_results] = (-b - sqrt(D)) / (2 * a);
              found_results++;
            }
          }
        }
      }
    }
  }


  printf(COLOR_BOLD_GREEN "Результат:" COLOR_WHITE);

  if (!found_results) {
    printf(" нет решений.");
  }

  for (int i = 0; i < found_results; i++) {
    for (int j = i + 1; j < found_results; j++) {
      if (fabs(results[i] - results[j]) < epsilon) {
        repeated_results[j] = true;
      }
    }

    if (!repeated_results[i]) {
      printf(" %lf", results[i]);
    }
  }

  printf("\n");
}


void flag_m(int argc, char* argv[]) {
  int numbers[2];
  convert_all_int_numbers(argc, argv, numbers);

  printf(COLOR_BOLD_GREEN "Результат: " COLOR_WHITE);

  if (numbers[0] % numbers[1] == 0) {
    printf("первое число кратко второму.\n");
  } else {
    printf("первое число не кратко второму.\n");
  }
}
