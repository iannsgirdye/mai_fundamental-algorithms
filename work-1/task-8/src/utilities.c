#include "../include/utilities.h"
#include "../include/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


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
      return _errorInvalidSystem();
    }
  }

  if (*number < 2 || *number > 36) {
    return _errorInvalidSystem();
  }

  return OK;
}
