#ifndef UTILITIES_H
#define UTILITIES_H


typedef enum {
  OK,
  INVALID_VALUE,
  INVALID_FORMAT
} returnStatus;


returnStatus getSystem(int *system);


#endif
