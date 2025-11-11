#include <stdio.h>
#include <stdlib.h>
#include "./vector.h"

typedef int T;
INCLUDE_VECTOR(T);

T copyVectorElement(T element) {
  return element;
}

void deleteVectorElement(T element) {
  return;
}

void scanVector(Vector *v, size_t size) {
  int x;
  for (size_t i = 0; i != size; ++i) {
    scanf("%d", &x);
    push_back_vector(v, x);
  }
}

void printVector(const char *vName, const Vector *v, size_t size) {
  printf("%s: ", vName);
  for (size_t i = 0; i != size; ++i) {
    printf("%d", get_at_vector(v, i));
    printf("%c", (i < size - 1) ? ' ' : '\n');
  }
}

int main() {

  Vector v1 = create_vector(BUFSIZ, &copyVectorElement, &deleteVectorElement);
  const size_t size = 5;
  scanVector(&v1, size);
  printVector("v1", &v1, size);

  Vector v2 = create_vector(0, NULL, NULL);
  printf("v1 == v2: %s\n", is_equal_vector(&v1, &v2) == 1 ? "true" : "false");
  copy_vector(&v2, &v1);
  printVector("v2", &v2, size);
  printf("v1 == v2: %s\n", is_equal_vector(&v1, &v2) == 1 ? "true" : "false");
  printf("4th element in v2: %d\n", get_at_vector(&v2, 3));
  delete_at_vector(&v2, 3);
  printf("4th element in v2: %d\n", get_at_vector(&v2, 3));
  printVector("v2", &v2, size);

  Vector *v3 = copy_vector_new(&v1);
  printf("v1 == v3: %s\n", is_equal_vector(&v1, v3) == 1 ? "true" : "false");
  
  delete_vector(v3);
  erase_vector(&v1);
  erase_vector(&v2);
  return 0;
}
