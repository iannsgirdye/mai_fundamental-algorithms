#ifndef SEARCH_H
#define SEARCH_H


#include "./utilities.h"


struct number {
  char strValue[33];
  int intValue;
};


returnStatus searchMaxNumber(struct number *maxNumber, const int system);
returnStatus printMaxNumber(struct number *maxNumber);


#endif
