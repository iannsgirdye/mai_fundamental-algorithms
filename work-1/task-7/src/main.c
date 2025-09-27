#include "../include/utilities.h"
#include "../include/converter.h"


int main(int argc, char* argv[]) {
  if (validateCountOfArguments(argc) != OK) {
    return 0;
  }

  if (converter(argv[1], argv[2]) != OK) {
    return 0;
  }

  return 0;
}
