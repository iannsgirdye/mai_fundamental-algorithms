#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>


void printHelp() {
  printf("Формат ввода: <программа> <вещественное число epsilon>\n");
}


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
