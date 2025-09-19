#include <stdio.h>
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
