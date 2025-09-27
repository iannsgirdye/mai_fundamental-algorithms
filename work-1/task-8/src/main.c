#include <limits.h>
#include "../include/utilities.h"
#include "../include/search.h"


int main() {
  int system = 0;
  if (getSystem(&system) != OK) {
    return 0;
  }

  struct number maxNumber;
  maxNumber.intValue = INT_MIN;

  if (searchMaxNumber(&maxNumber, system) != OK) {
    return 0;
  }

  if (printMaxNumber(&maxNumber) != OK) {
    return 0;
  }

  return 0;
}
