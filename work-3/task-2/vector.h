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

Vector create_vector(size_t initial_capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE)) { 
  Vector vector = {.size = 0, .capacity = 0, .CopyVoidPtr = NULL, .DeleteVoidPtr = NULL};
  vector.data = (VECTOR_TYPE *)malloc(initial_capacity * sizeof(VECTOR_TYPE));
  if (vector.data == NULL) {
    return vector;
  }
  vector.capacity = initial_capacity;
  vector.CopyVoidPtr = CopyFunc;
  vector.DeleteVoidPtr = DeleteFunc;
  return vector;
} 


#endif
