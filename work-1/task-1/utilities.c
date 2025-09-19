#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utilities.h"
#include "colors.h"


return_status validate_arguments_count(int argc, char* argv[]) {
  if (argc == 2 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0)) {
    printf(
      "Формат: <программа> <натуральное число> <флаг>\n\n"
      "-i   Информация о программе.\n\n"
      "-h   Вывод натуральных чисел в пределах 100 включительно, кратных числу x.\n\n"
      "-p   Определение числа x: простое или составное.\n\n"
      "-s   Разделение числа x на отдельные цифры системы счисления с основанием 16,\n"
      "     вывод каждой цифры числа по-отдельности через пробел от старших разрядов\n" 
      "     к младшим и без ведущих нулей в строковом представлении.\n\n"
      "-e   Вывод таблицы степеней для всех показателей в диапазоне от 1 до x (x не больше 10)\n"
      "     оснований от 1 до 10.\n\n"
      "-a   Вычисление суммы всех натуральных чисел от 1 до x.\n\n"
      "-f   Вычисление факториала числа x.\n"
    );
    return USAGE_HELP;
  }
  
  if (argc != 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "некорректное количество аргуменов (формат: <программа> <число> <флаг операции>).\n"
    );
    return INCORRECT_ARGUMENTS_COUNT;
  }

  return OK;
}


return_status validate_x(char* str_x, int* x) {
  char* endptr;
  long int converted_x = strtol(str_x, &endptr, 10);

  if (converted_x < 1 || converted_x > INT_MAX) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "число должно быть натуральным и в диапозоне типа int.\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  if (*endptr != '\0') {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "введено некорректное натуральное число.\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  *x = converted_x;
  return OK;
}


return_status validate_flag(char* str_flag, char* flag) {
  if (strlen(str_flag) != 2) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "введён некорректный формат флага (формат: -f или /f).\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  if (str_flag[0] == '/' || str_flag[0] == '-') {
    switch (str_flag[1]) {
      case 'h':
      case 'p':
      case 's':
      case 'e':
      case 'a':
      case 'f':
        *flag = str_flag[1];
        break;
      default:
        printf(
          COLOR_BOLD_RED "Ошибка: "
          COLOR_WHITE    "введён несуществующий флаг.\n"
        );
        return INCORRECT_ARGUMENT_VALUE;
    }
  } else {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE    "введён некорректный флаг (формат: -f или /f).\n"
    );
    return INCORRECT_ARGUMENT_VALUE;
  }

  return OK;
}
