#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MIN_ROMAN_NUMERAL 0
#define MAX_ROMAN_NUMERAL 3999
#define PARTS_COUNT 4
#define TYPES_COUNT 10


returnStatus flagRo(const int number, char *strRomanNumeral) {
  if (number < MIN_ROMAN_NUMERAL || number > MAX_ROMAN_NUMERAL) {
    return INVALID_ROMAN_NUMERAL;
  }

  const char *romanParts[PARTS_COUNT][TYPES_COUNT] = {
    {"", "M", "MM", "MMM"},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
  };
  const int numberParts[PARTS_COUNT] = {
    number / 1000,
    (number / 100) % 10,
    (number / 10) % 10,
    number % 10
  };
  
  for (size_t i = 0; i != PARTS_COUNT; ++i) {
    strcat(strRomanNumeral, romanParts[i][numberParts[i]]);  
  }

  return OK;
}
