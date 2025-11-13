#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define INCLUDE_LINKED_LIST(STRUCT_NAME, LIST_TYPE)                                                                      \
  typedef struct Node {                                                                                                  \
    LIST_TYPE data;                                                                                                      \
    struct Node *prev;                                                                                                   \
    struct Node *next;                                                                                                   \
  } Node;                                                                                                                \
                                                                                                                         \
  typedef struct {                                                                                                       \
    Node *head;                                                                                                          \
    Node *tail;                                                                                                          \
    size_t size;                                                                                                         \
  } LinkedList;                                                                                                          \
                                                                                                                         \
  LinkedList STRUCT_NAME##_create_list() {                                                                               \
    LinkedList l = {.head = NULL, .tail = NULL, .size = 0};                                                              \
    return l;                                                                                                            \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_erase_list(LinkedList *list) {                                                                      \
    if (list == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *current = list->head;                                                                                          \
    Node *next;                                                                                                          \
    for (size_t i = 0; i != list->size; ++i) {                                                                           \
      next = current->next;                                                                                              \
      free(current);                                                                                                     \
      current = next;                                                                                                    \
    }                                                                                                                    \
                                                                                                                         \
    list->size = 0;                                                                                                      \
    list->head = NULL;                                                                                                   \
    list->tail = NULL;                                                                                                   \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_delete_list(LinkedList *list) {                                                                     \
    if (list == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    erase_list(list);                                                                                                    \
    free(list);                                                                                                          \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_push_back_list(LinkedList *list, LIST_TYPE value) {                                                 \
    if (list == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *node = (Node *)malloc(sizeof(Node));                                                                           \
    if (node == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
    node->data = value;                                                                                                  \
    node->prev = list->tail;                                                                                             \
    node->next = NULL;                                                                                                   \
                                                                                                                         \
    if (list->size > 0) {                                                                                                \
      list->tail->next = node;                                                                                           \
    } else {                                                                                                             \
      list->head = node;                                                                                                 \
    }                                                                                                                    \
    list->tail = node;                                                                                                   \
    ++(list->size);                                                                                                      \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_push_front_list(LinkedList *list, LIST_TYPE value) {                                                \
    if (list == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *node = (Node *)malloc(sizeof(Node));                                                                           \
    if (node == NULL) {                                                                                                  \
      return;                                                                                                            \
    }                                                                                                                    \
    node->data = value;                                                                                                  \
    node->prev = NULL;                                                                                                   \
    node->next = list->head;                                                                                             \
    list->head->prev = node;                                                                                             \
    list->head = node;                                                                                                   \
    ++(list->size);                                                                                                      \
  }                                                                                                                      \
                                                                                                                         \
  LIST_TYPE STRUCT_NAME##_pop_back_list(LinkedList *list) {                                                              \
    if (list == NULL || list->size == 0) {                                                                               \
      return 0;                                                                                                          \
    }                                                                                                                    \
                                                                                                                         \
    Node *node = list->tail;                                                                                             \
    LIST_TYPE nodeData = node->data;                                                                                     \
    list->tail = node->prev;                                                                                             \
    list->tail->next = NULL;                                                                                             \
    free(node);                                                                                                          \
    return nodeData;                                                                                                     \
  }                                                                                                                      \
                                                                                                                         \
  LIST_TYPE STRUCT_NAME##_pop_front_list(LinkedList *list) {                                                             \
    if (list == NULL || list->size == 0) {                                                                               \
      return 0;                                                                                                          \
    }                                                                                                                    \
                                                                                                                         \
    Node *node = list->head;                                                                                             \
    LIST_TYPE nodeData = node->data;                                                                                     \
    list->head = node->next;                                                                                             \
    list->head->prev = NULL;                                                                                             \
    free(node);                                                                                                          \
    return nodeData;                                                                                                     \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_insert_at_list(LinkedList *list, size_t index, LIST_TYPE value) {                                   \
    if (list == NULL || index >= list->size) {                                                                           \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *newNode = (Node *)malloc(sizeof(Node));                                                                        \
    if (newNode == NULL) {                                                                                               \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *currentNode = list->head;                                                                                      \
    for (size_t i = 0; i != index; ++i) {                                                                                \
      currentNode = currentNode->next;                                                                                   \
    }                                                                                                                    \
                                                                                                                         \
    newNode->data = value;                                                                                               \
    newNode->prev = currentNode->prev;                                                                                   \
    newNode->next = currentNode;                                                                                         \
                                                                                                                         \
    newNode->prev->next = newNode;                                                                                       \
    newNode->next->prev = newNode;                                                                                       \
                                                                                                                         \
    ++(list->size);                                                                                                      \
  }                                                                                                                      \
                                                                                                                         \
  void STRUCT_NAME##_delete_at_list(LinkedList *list, size_t index) {                                                    \
    if (list == NULL || index >= list->size) {                                                                           \
      return;                                                                                                            \
    }                                                                                                                    \
                                                                                                                         \
    Node *currentNode = list->head;                                                                                      \
    for (size_t i = 0; i != index; ++i) {                                                                                \
      currentNode = currentNode->next;                                                                                   \
    }                                                                                                                    \
                                                                                                                         \
    currentNode->prev->next = currentNode->next;                                                                         \
    currentNode->next->prev = currentNode->prev;                                                                         \
    free(currentNode);                                                                                                   \
    --(list->size);                                                                                                      \
  }                                                                                                                      \
                                                                                                                         \
  LIST_TYPE STRUCT_NAME##_get_at_list(const LinkedList *list, size_t index) {                                            \
    if (list == NULL || index >= list->size) {                                                                           \
      return 0;                                                                                                          \
    }                                                                                                                    \
                                                                                                                         \
    Node *currentNode = list->head;                                                                                      \
    for (size_t i = 0; i != index; ++i) {                                                                                \
      currentNode = currentNode->next;                                                                                   \
    }                                                                                                                    \
                                                                                                                         \
    return currentNode->data;                                                                                            \
  }                                                                                                                      \
                                                                                                                         \
  int STRUCT_NAME##_is_equal_list(const LinkedList *l1, const LinkedList *l2, int (*Comporator)(LIST_TYPE, LIST_TYPE)) { \
    if (l1 == NULL && l2 == NULL) {                                                                                      \
      return TRUE;                                                                                                       \
    }                                                                                                                    \
    if (l1 == NULL || l2 == NULL) {                                                                                      \
      return FALSE;                                                                                                      \
    }                                                                                                                    \
    if (l1->size != l2->size) {                                                                                          \
      return FALSE;                                                                                                      \
    }                                                                                                                    \
                                                                                                                         \
    Node *currentNodeList1 = l1->head;                                                                                   \
    Node *currentNodeList2 = l2->head;                                                                                   \
    for (size_t i = 0; i != l1->size; ++i) {                                                                             \
      if (Comporator(currentNodeList1->data, currentNodeList2->data) != 0) {                                             \
        return FALSE;                                                                                                    \
      }                                                                                                                  \
      currentNodeList1 = currentNodeList1->next;                                                                         \
      currentNodeList2 = currentNodeList2->next;                                                                         \
    }                                                                                                                    \
    return TRUE;                                                                                                         \
  }

#endif
