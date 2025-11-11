#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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

int _realloc_vector(Vector *v, size_t need_capacity) {
  VECTOR_TYPE *tmp = (VECTOR_TYPE *)realloc(v->data, need_capacity * sizeof(VECTOR_TYPE));
  if (tmp == NULL) {
    return FALSE;
  }
  v->data = tmp;
  v->capacity = need_capacity;
  return TRUE;
}

void erase_vector(Vector *v) {
  if (v == NULL || v->data == NULL || v->DeleteVoidPtr == NULL) {
    return;
  }

  for (size_t i = 0; i != v->size; ++i) {
    v->DeleteVoidPtr(v->data[i]);
  }
  v->size = 0;
  v->capacity = 0;
}

int is_equal_vector(const Vector *v1, const Vector *v2) {
  if (v1 == NULL || v2 == NULL || v1->data == NULL || v2->data == NULL) {
    return FALSE;
  }
  
  if (v1->size != v2->size) {
    return FALSE;
  }

  for (size_t i = 0; i != v1->size; ++i) {
    if (v1->data[i] != v2->data[i]) {
      return FALSE;
    }
  }
  return TRUE;
}

void copy_vector(Vector *dest, const Vector *src) {
  if (src == NULL || src->data == NULL || src->CopyVoidPtr == NULL) {
    return;
  }
  if (dest == NULL || dest->data == NULL || dest->DeleteVoidPtr == NULL) {
    return;
  }
  if (dest->capacity < src->size) {
    if (!_realloc_vector(dest, src->capacity)) {
      return;
    }
  }

  for (size_t i = 0; i != dest->size; ++i) {
    dest->DeleteVoidPtr(dest->data[i]);
    dest->data[i] = src->CopyVoidPtr(src->data[i]);
  }

  for (size_t i = dest->size; i != src->size; ++i) {
    dest->data[i] = src->CopyVoidPtr(src->data[i]);
  }

  dest->size = src->size;
  dest->capacity = src->capacity;
  dest->CopyVoidPtr = src->CopyVoidPtr;
  dest->DeleteVoidPtr = src->DeleteVoidPtr;
}

#endif
