#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "colors.h"


return_status help() {
  printf(
    "Формат: <программа> <флаг> <параметры>\n\n"
    "-q   Первый параметр (вещественное число) задаёт точность сравнения\n"
    "     вещественных чисел (эпсилон), оставшиеся три (вещественные числа)\n"
    "     являются коэффициентами квадратного уравнения;\n"
    "     вывод решения этого уравнения при всевозможных уникальных\n"
    "     перестановках значений коэффициентов при степенях переменной.\n\n"
    "-m   Задаётся два ненулевых целых числа;\n"
    "     определение кратности первого числа второму.\n\n"
    "-t   Первый параметр (вещественное число) задаёт точность сравнения\n"
    "     вещественных чисел (эпсилон);\n"
    "     проверка на возможность оставшимся трём (вещественные числа)\n"
    "     параметрам являться длинами сторон прямоугольного треугольника.\n"
  );
  return USAGE_HELP;
}


return_status error_invalid_count_of_arguments() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE    "некорректное количество аргументов (справка: <программа> -h).\n"
  );
  return INVALID_COUNT_OF_ARGUMENTS;
}


return_status validate_arguments_count(int argc, char* argv[]) {
  if (argc == 1) {
    return error_invalid_count_of_arguments();
  }

  if (argc == 2 && (argv[1][0] == '-' || argv[1][0] == '/') && argv[1][1] == 'h') {
    return help();
  }

  if (argv[1][0] == '-' || argv[1][0] == '/') {
    switch (argv[1][1]) {
      case 'q':
      case 't':
        if (argc != 6) {
          return error_invalid_count_of_arguments();
        }
        break;
      case 'm':
        if (argc != 4) {
          return error_invalid_count_of_arguments();
        }
        break;
      default:
        printf(COLOR_BOLD_RED "Ошибка: " COLOR_WHITE "некорректный флаг.\n");
    }
  } else {
    printf(COLOR_BOLD_RED "Ошибка: " COLOR_WHITE "отсутствует флаг.\n");
    return INVALID_ARGUMENT;
  }

  return OK;
}


return_status _convert_double_number(char* str_number, double* number) {
  char* endptr;

  *number = strtod(str_number, &endptr);
  if (*endptr != '\0') {
    printf(COLOR_BOLD_RED "Ошибка: " COLOR_WHITE "некорректный формат вещественного числа.\n");
    return INVALID_ARGUMENT;
  }

  return OK;
}


return_status convert_all_double_numbers(int argc, char* argv[], double numbers[]) {
  for (int i = 0; i < argc - 2; i++) {
    if (_convert_double_number(argv[i + 2], &numbers[i]) != OK) {
      return INVALID_ARGUMENT;
    }
  }
}


return_status _convert_int_number(char* str_number, int* number) {
  char* endptr;

  *number = (int)strtol(str_number, &endptr, 10);
  if (*endptr != '\0') {
    printf(COLOR_BOLD_RED "Ошибка: " COLOR_WHITE "некорректный формат целого числа.\n");
    return INVALID_ARGUMENT;
  }

  return OK;
}


return_status convert_all_int_numbers(int argc, char* argv[], int numbers[]) {
  for (int i = 0; i < argc - 2; i++) {
    if (_convert_int_number(argv[i + 2], &numbers[i]) != OK) {
      return INVALID_ARGUMENT;
    }
  }
}