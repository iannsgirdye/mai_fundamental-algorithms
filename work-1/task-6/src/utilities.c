#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>


returnStatus validateCountOfArguments(int argc) {
  if (argc == 2) {
    return OK;
  }

  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "введено некорректное количество аргументов (справка: флаг \"-h\").\n"
  );
  return INVALID_COUNT_OF_ARGUMENTS;
}
