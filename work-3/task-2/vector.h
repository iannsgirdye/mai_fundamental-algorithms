#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef int VECTOR_TYPE;

typedef struct { 
  VECTOR_TYPE *data; 
  size_t size; 
  size_t capacity; 
  VECTOR_TYPE (*CopyVoidPtr)(VECTOR_TYPE); 
  void (*DeleteVoidPtr)(VECTOR_TYPE); 
} Vector; 



#endif
