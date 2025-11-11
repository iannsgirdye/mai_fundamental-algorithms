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
  Vector v = {.size = 0, .capacity = 0, .CopyVoidPtr = NULL, .DeleteVoidPtr = NULL};
  v.data = (VECTOR_TYPE *)malloc(initial_capacity * sizeof(VECTOR_TYPE));
  if (v.data == NULL) {
    return v;
  }
  v.capacity = initial_capacity;
  v.CopyVoidPtr = CopyFunc;
  v.DeleteVoidPtr = DeleteFunc;
  return v;
} 

void erase_vector(Vector *v) {
  if (v == NULL || v->data == NULL) {
    return;
  }

  for (size_t i = 0; i != v->size; ++i) {
    v->DeleteVoidPtr(v->data[i]);
  }
  v->size = 0;
  v->capacity = 0;
}

#endif
