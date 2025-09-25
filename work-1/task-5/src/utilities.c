#include "utilities.h"


returnStatus validateCountOfArguments(int argc, char* argv[]) {
  if (argc < 2 || argc > 3) {
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  if (argv[1][1] == 'n' && argv == 2) {
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  return OK;
}