#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>


returnStatus validateCountOfArguments(const int argc) {
  if (argc == 3) {
    return OK;
  }

  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "введено некорректное количество аргументов "
    "(формат: <программа> <входной файл> <выходной файл>).\n"
  );
  return INVALID_COUNT_OF_ARGUMENTS;
}
