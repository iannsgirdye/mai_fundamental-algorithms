#ifndef ERRORS_H
#define ERRORS_H

#include "./utilities.h"


returnStatus _errorInvalidFile(const char fileType[]);
returnStatus _errorInvalidDataInFile();
returnStatus _errorIntOverflow();


#endif