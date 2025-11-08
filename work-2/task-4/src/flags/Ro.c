#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <string.h>


struct romanDigit {
  char letter;
  int number;
};

enum romanDigitsValues {
  I = 1,
  V = 5,
  X = 10,
  L = 50,
  C = 100,
  D = 500,
  M = 1000
};


returnStatus _defineRomanDigit(const char strRomanDigit, int *romanDigit) {
  const struct romanDigit romanDigits[7] = {{'I', I}, {'V', V}, {'X', X}, {'L', L}, {'C', C}, {'D', D}, {'M', M}};

  for (size_t i = 0; i != 7; ++i) {
    if (strRomanDigit == romanDigits[i].letter) {
      *romanDigit = romanDigits[i].number;
      return OK;
    }
  }
  return INVALID_ROMAN_DIGIT;
}


returnStatus _checkRepeatsOfRomanDigits(const char *romanNumeral) {
  const char *incorrectSubstrs[7] = {"VV", "LL", "DD", "IIII", "XXXX", "CCCC", "MMMM"};

  for (size_t i = 0; i != 7; ++i) {
    if (strstr(romanNumeral, incorrectSubstrs[i])) {
      return INVALID_ROMAN_NUMERAL;
    }
  }
  return OK;
}


int _summand(const int prevRomanDigit, const int romanDigit) {
  if (prevRomanDigit >= romanDigit) {
    return prevRomanDigit;
  }
  return -prevRomanDigit;
}


returnStatus flagRo(const char *romanNumeral, int *number) {
  if (_checkRepeatsOfRomanDigits(romanNumeral) != OK) {
    return INVALID_ROMAN_NUMERAL;
  }

  int result = 0;
  int romanDigit, prevRomanDigit;
  const size_t len = strlen(romanNumeral);

  for (size_t i = 0; i != len; ++i) {
    if (_defineRomanDigit(romanNumeral[i], &romanDigit) != OK) {
      return INVALID_ROMAN_DIGIT;
    }
    
    if (i > 0) {
      result += _summand(prevRomanDigit, romanDigit);
    }

    prevRomanDigit = romanDigit;
  }
  result += romanDigit;
  
  *number = result;
  return OK;
}
