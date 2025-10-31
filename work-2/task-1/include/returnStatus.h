#ifndef RETURN_STATUS_H
#define RETURN_STATUS_H


typedef enum {
  SYSTEM_IS_NOT_DECIMAL_NUMBER = -5,
  INVALID_SYSTEM = -4,
  INVALID_DECIMAL = -2,
  INVALID_ARRAY = -1,
  OK = 0
} returnStatus;


#endif
