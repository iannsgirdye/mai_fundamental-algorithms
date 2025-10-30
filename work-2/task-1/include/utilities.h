#ifndef UTILITIES_H
#define UTILITIES_H


#include <stdbool.h>
#include <stdlib.h>
#include "./returnStatus.h"


returnStatus checkArray(const size_t size, const void *array);
returnStatus getFractions(const size_t size, double fractions[]);
returnStatus printResults(const size_t size, const bool results[]);


#endif
