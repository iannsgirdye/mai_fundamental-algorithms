#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>

typedef double LIST_TYPE;

typedef struct Node {
  double *data;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct {
  Node *head; 
  Node *tail;
  size_t size;
} LinkedList;

// Создание пустого списка
LinkedList create_list() {
  LinkedList l = {.head = NULL, .tail = NULL, .size = 0};
  return l;
}

// Очистка содержимого списка (удаление всех элементов) 
void erase_list(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  
  Node *current = list->head;
  Node *next;
  for (size_t i = 0; i != list->size; ++i) {
    next = current->next;
    free(current);
    current = next;
  }
}

// Полное удаление списка (освобождение ресурсов)
void delete_list(LinkedList *list) {
  erase_list(list);
  free(list);
}

// Добавление элемента в конец списка
void push_back_list(LinkedList *list, LIST_TYPE value);

// Добавление элемента в начало списка
void push_front_list(LinkedList *list, LIST_TYPE value);

// Удаление элемента с конца списка 
double pop_back_list(LinkedList *list);

// Удаление элемента с начала списка
double pop_front_list(LinkedList *list);

// Вставка элемента по индексу
void insert_at_list(LinkedList *list, size_t index, LIST_TYPE value);

// Удаление элемента по индексу
void delete_at_list(LinkedList *list, size_t index);

// Получение элемента по индексу
double get_at_list(const LinkedList *list, size_t index);

// Сравнение двух списков (лексикографически): возвращает `1` — равны, `0` — не равны
int is_equal_list(const LinkedList *l1, const LinkedList *l2);

#endif
