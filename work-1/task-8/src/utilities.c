#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


returnStatus _errorIncorrectSystem() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "система счисления должна быть в диапозоне [2..36].\n"
  );
  return INVALID_VALUE;
}


returnStatus getSystem(int *number) {
  char symbol;
  for (size_t i = 0; i <= 2; ++i) {
    symbol = getchar();
    if (isdigit(symbol) && i != 2) {
      *number *= 10;
      *number += symbol - '0';
    } else if (symbol == '\n' && i != 0) {
      break;
    } else {
      return _errorIncorrectSystem();
    }
  }

  if (*number < 2 || *number > 36) {
    return _errorIncorrectSystem();
  }

  return OK;
}
