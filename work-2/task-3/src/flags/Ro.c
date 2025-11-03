#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <string.h>


#define COUNT_OF_ROMAN_DIGITS 7


typedef struct {
  char letter;
  int number;
} romanDigit;

typedef enum {
  I = 1,
  V = 5,
  X = 10,
  L = 50,
  C = 100,
  D = 500,
  M = 1000
} romanDigits;


returnStatus _defineRomanDigit(const char strRomanDigit, int *result) {
  const romanDigit romanDigits[] = {{'I', I}, {'V', V}, {'X', X}, {'L', L}, {'C', C}, {'D', D}, {'M', M}};

  for (size_t i = 0; i != COUNT_OF_ROMAN_DIGITS; ++i) {
    if (strRomanDigit == romanDigits[i].letter) {
      *result = romanDigits[i].number;
      return OK;
    }
  }
  return INVALID_ROMAN_DIGIT;
}


returnStatus _areCorrectRepeatsOfRomanDigits(const char *strRomanNumeral) {
  const char *incorrectSubstrs[] = {"VV", "LL", "DD", "IIII", "XXXX", "CCCC", "MMMM"};

  for (size_t i = 0; i != COUNT_OF_ROMAN_DIGITS; ++i) {
    if (strstr(strRomanNumeral, incorrectSubstrs[i])) {
      return INVALID_ROMAN_NUMERAL;
    }
  }
  return OK;
}


int _defineSummandForResult(const int prevRomanDigit, const int romanDigit) {
  if (prevRomanDigit >= romanDigit) {
    return prevRomanDigit;
  }
  return -prevRomanDigit;
}


returnStatus flagRo(const char *strRomanNumeral, int *_result) {
  if (_areCorrectRepeatsOfRomanDigits(strRomanNumeral) != OK) {
    return INVALID_ROMAN_NUMERAL;
  }

  int result = 0;
  int romanDigit, prevRomanDigit;
  const size_t len = strlen(strRomanNumeral);

  for (size_t i = 0; i != len; ++i) {
    if (_defineRomanDigit(strRomanNumeral[i], &romanDigit) != OK) {
      return INVALID_ROMAN_DIGIT;
    }
    
    if (i > 0) {
      result += _defineSummandForResult(prevRomanDigit, romanDigit);
    }

    prevRomanDigit = romanDigit;
  }
  result += romanDigit;
  
  *_result = result;
  return OK;
}
