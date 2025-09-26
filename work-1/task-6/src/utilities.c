#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _printHelp() {
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


returnStatus validateSecondArgument(char* argv[], double* epsilon) {
  if (strcmp(argv[1], "-h") == 0) {
    _printHelp();
    return HELP_USAGE;
  }

  char* endptr;
  double strEpsilon = strtod(argv[1], &endptr);
  if (*endptr != '\0') {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "введено некорректное значение epsilon (справка: флаг \"-h\").\n"
    );
    return INVALID_ARGUMENT;
  }

  *epsilon = strEpsilon;
  return OK;
}
