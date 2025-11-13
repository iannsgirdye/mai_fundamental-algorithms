# Работа №3, задача №2

Реализуйте библиотеку, предоставляющую пользователю функционал динамического массива (`Vector`)
для произвольного типа элементов (используя макросы).

Важно: в одной программе, где используется данная библиотека, может быть определён
только один тип значений массива. Указатель на функцию копирования (поверхностного или глубокого)
и удаления необходимо передавать в рамках функции `create_vector` и хранить в структуре `Vector`.

Структура вектора, где `*data` — указатель на элементы, `size` — текущее количество элементов, 
`capacity` — вместимость (количество выделенных элементов)
``` c
typedef struct {
  VECTOR_TYPE *data;
  size_t size;
  size_t capacity;
  VECTOR_TYPE (*CopyVoidPtr)(VECTOR_TYPE);
  void (*DeleteVoidPtr)(VECTOR_TYPE);
} Vector;
``` 

Создание нового вектора
``` c
Vector create_vector(size_t initial_capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE));
```

Удаление внутреннего содержимого вектора (`data`, `size = 0`, `capacity = 0`)
``` c
void erase_vector(Vector *v);
```

Сравнение двух векторов (лексикографически): возвращает `1` — равны, `0` — не равны
``` c
int is_equal_vector(const Vector *v1, const Vector *v2);
```

Копирование содержимого одного вектора в другой (существующий)
``` c
void copy_vector(Vector *dest, const Vector *src);
```

Создание нового вектора в динамической памяти и копирование содержимого
``` c
Vector *copy_vector_new(const Vector *src);
```

Добавление элемента в конец вектора
``` c
void push_back_vector(Vector *v, VECTOR_TYPE value);
```

Удаление элемента по индексу
``` c
void delete_at_vector(Vector *v, size_t index);
```

Получение элемента по индексу
```c
VECTOR_TYPE get_at_vector(const Vector *v, size_t index);
```

Освобождение памяти, занимаемой экземпляром вектора
``` c
void delete_vector(Vector *v);
```
