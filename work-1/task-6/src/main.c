#include "../include/utilities.h"
#include "../include/calculations.h"
#include <stdio.h>


int main(int argc, char* argv[]) {
  if (validateCountOfArguments(argc) != OK) {
    return 0;
  }

  double epsilon;
  if (validateSecondArgument(argv, &epsilon) != OK) {
    return 0;
  }

  calculateIntegrals(epsilon);

  return 0;
}
