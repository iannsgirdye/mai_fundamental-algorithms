#include "../include/function.h"
#include "../include/utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SIZE 4


int main() {
  bool results[SIZE];

  int system;
  if (getSystem(&system) != OK) {
    return !OK;
  }

  double fractions[SIZE];
  if (getFractions(SIZE, fractions) != OK) {
    return !OK;
  }
  
  if (defineFractionsFinite(
    system, results, SIZE, 
    fractions[0], fractions[1], fractions[2], fractions[3]
  ) != OK) {
    return !OK;
  }

  if (printResults(SIZE, results) != OK) {
    return !OK;
  }

  return 0;
}
