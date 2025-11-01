#ifndef FUNCTION_H
#define FUNCTION_H


#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./returnStatus.h"


returnStatus defineFractionsFinite(const int system, bool results[], const size_t argc, ...);


#endif
