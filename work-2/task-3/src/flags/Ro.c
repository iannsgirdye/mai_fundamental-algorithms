#include "../../include/flags.h"
#include <stdlib.h>
#include <string.h>


#define COUNT_OF_ROMAN_DIGITS 7
#define INCORRECT_ROMAN_NUMERAL -1


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


int _defineRomanDigit(const char strRomanDigit) {
  const romanDigit romanDigits[] = {{'I', I}, {'V', V}, {'X', X}, {'L', L}, {'C', C}, {'D', D}, {'M', M}};

  for (size_t i = 0; i != COUNT_OF_ROMAN_DIGITS; ++i) {
    if (strRomanDigit == romanDigits[i].letter) {
      return romanDigits[i].number;
    }
  }
  return 0;
}


int _isCorrectRomanDigit(const int romanDigit) {
  return romanDigit > 0;
}


int _areCorrectRepeatsOfRomanDigits(const char *strRomanNumeral) {
  const char *incorrectSubstrs[] = {"VV", "LL", "DD", "IIII", "XXXX", "CCCC", "MMMM"};

  for (size_t i = 0; i != COUNT_OF_ROMAN_DIGITS; ++i) {
    if (strstr(strRomanNumeral, incorrectSubstrs[i])) {
      return 0;
    }
  }
  return 1;
}


int _defineSummandForResult(const int prevRomanDigit, const int romanDigit) {
  if (prevRomanDigit >= romanDigit) {
    return prevRomanDigit;
  }
  return -prevRomanDigit;
}


int flagRo(const char *strRomanNumeral) {
  if (!_areCorrectRepeatsOfRomanDigits(strRomanNumeral)) {
    return INCORRECT_ROMAN_NUMERAL;
  }

  int result = 0;
  int romanDigit, prevRomanDigit;
  const size_t len = strlen(strRomanNumeral);

  for (size_t i = 0; i != len; ++i) {
    romanDigit = _defineRomanDigit(strRomanNumeral[i]);
    if (!_isCorrectRomanDigit(romanDigit)) {
      return INCORRECT_ROMAN_NUMERAL;
    }
    
    if (i > 0) {
      result += _defineSummandForResult(prevRomanDigit, romanDigit);
    }

    prevRomanDigit = romanDigit;
  }
  result += romanDigit;
  
  return result;
}
