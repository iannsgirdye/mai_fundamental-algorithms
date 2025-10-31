#ifndef ERRORS_H
#define ERRORS_H


#include <stdio.h>
#include "./returnStatus.h"


returnStatus _errorInvalidArray(const char *functionName);
returnStatus _errorSystemIsNotDecimalNumber(const char *text);
returnStatus _errorInvalidSystem();
returnStatus _errorInvalidValue(const double value);


#endif
