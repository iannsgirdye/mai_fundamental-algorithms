#include <stdio.h>
#include "../include/utilities.h"
#include "../include/converter.h"


int main() {
  int number;
  if (getNumber(&number) != OK) {
    return 0;
  }

  int basePow;
  if (getBasePow(&basePow) != OK) {
    return 0;
  }
  
  char convertedNumber[BUFSIZ];
  if (convertNumber(number, basePow, convertedNumber) != OK) {
    return 0;
  }

  printf("%d = %s with base 2**%d\n", number, convertedNumber, basePow);

  return 0;
}
