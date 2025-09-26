#include "../include/converter.h"
#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>


#define max(a, b) (a > b) ? a : b


struct inputedSymbol {
  char symbol;
  int system;
};

struct fixedNumber {
  char strNumber[32];
  size_t strNumberLen;
  int system;
  long int tenNumber;
};


returnStatus _errorInvalidFile(const char fileType[]) {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "не удалось открыть %s файл.\n",
    fileType
  );
  return INVALID_FILE;
}


returnStatus _errorInvalidDataInFile() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "в файле должны быть только латинские буквы, цифры и пробельные символы.\n"
  );
  return INVALID_DATA_IN_FILE;
}


returnStatus _errorIntOverflow() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "файл содержит число, которое выходит за отрезок [%d; %d].\n",
    INT_MIN, INT_MAX
  );
  return INVALID_DATA_IN_FILE;
}


returnStatus _fixNumberData(
  struct inputedSymbol* _inputedSymbol, 
  struct fixedNumber* _fixedNumber, 
  char startLetter
) {
  if (_fixedNumber->strNumberLen == 32) {
    return _errorIntOverflow();
  }

  _inputedSymbol->system = _inputedSymbol->symbol - startLetter;
  _inputedSymbol->system += (startLetter == '0') ? 1 : 11;
  _fixedNumber->system = max(_inputedSymbol->system, _fixedNumber->system);
  _fixedNumber->strNumber[_fixedNumber->strNumberLen] = _inputedSymbol->symbol;
  _fixedNumber->strNumberLen++;

  return OK;
}


returnStatus _convertNumberToTenSystem(struct fixedNumber* _fixedNumber) {
  char strDigit;
  for (size_t i = 0; i != _fixedNumber->strNumberLen; ++i) {
    _fixedNumber->tenNumber *= _fixedNumber->system;
    strDigit = _fixedNumber->strNumber[i];
    _fixedNumber->tenNumber += isdigit(strDigit) ? strDigit - '0' : strDigit - 'A' + 10;
    if (_fixedNumber->tenNumber > INT_MAX) {
      return _errorIntOverflow();
    }
  }

  return OK;
}


void _printNumberData(FILE* outputFile, struct fixedNumber* _fixedNumber) {
  _fixedNumber->strNumber[_fixedNumber->strNumberLen] = '\0';
  fprintf(
    outputFile,
    "%s %d %ld\n",
    _fixedNumber->strNumber,
    _fixedNumber->system,
    _fixedNumber->tenNumber
  );
}


void _initDataOfFixedNumber(struct fixedNumber* _fixedNumber) {
  _fixedNumber->strNumberLen = 0;
  _fixedNumber->system = 2;
  _fixedNumber->tenNumber = 0;
}


returnStatus converter(const char inputFileName[], const char outputFileName[]) {
  FILE* inputFile = fopen(inputFileName, "r");
  if (inputFile == NULL) {
    return _errorInvalidFile("входной");
  }

  FILE* outputFile = fopen(outputFileName, "w");
  if (outputFile == NULL) {
    return _errorInvalidFile("выходной");
  }

  struct inputedSymbol _inputedSymbol;
  struct fixedNumber _fixedNumber;
  _initDataOfFixedNumber(&_fixedNumber);

  while ((_inputedSymbol.symbol = fgetc(inputFile)) != EOF) {
    if (isdigit(_inputedSymbol.symbol)) {
      if (_fixNumberData(&_inputedSymbol, &_fixedNumber, '0') != OK) {
        return INVALID_DATA_IN_FILE;
      }
    }

    else if (isalpha(_inputedSymbol.symbol)) {
      _inputedSymbol.symbol = toupper(_inputedSymbol.symbol);
      if (_fixNumberData(&_inputedSymbol, &_fixedNumber, 'A') != OK) {
        return INVALID_DATA_IN_FILE;
      }
    } 

    else if (isspace(_inputedSymbol.symbol)) {
      if (_convertNumberToTenSystem(&_fixedNumber) != OK) {
        return INVALID_DATA_IN_FILE;
      }
      _printNumberData(outputFile, &_fixedNumber);
      _initDataOfFixedNumber(&_fixedNumber);
    } 
    
    else {
      fclose(inputFile);
      fclose(outputFile);
      return _errorInvalidDataInFile();
    }
  }
  
  if (_fixedNumber.strNumberLen > 0) {  
    if (_convertNumberToTenSystem(&_fixedNumber) != OK) {
      return INVALID_DATA_IN_FILE;
    }
    _printNumberData(outputFile, &_fixedNumber);
  }

  fclose(inputFile);
  fclose(outputFile);

  return OK;
}
