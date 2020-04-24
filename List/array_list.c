#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  int *array; // динамический массив, в котором будут раниться все данные
  int length; // размер списка: последний занятый индекс в array
  int capacity; // ёмкость списка: реальный размер массива array
  int size;     // length + 1

  // если нужно, то добавьте дополнительные поля
};

void Printf(List *this) {
  for (int i = 0; i < this->size; i++) {
    printf("%d ", this->array[i]);
    if (this->size == i + 1) {
      printf("\n");
    }
  }
}

void MicroMemory(List *this) {
  this->capacity /= 4;

  int *arr = (int *)malloc(this->capacity * sizeof(int));

  for (int i = 0; i < this->size + 1; i++) {
    arr[i] = (this->array)[i];
  }
  if (!arr)
    exit(-1);

  free(this->array);
  this->array = arr;
  arr = NULL;
  free(arr);
}

void AllocMemory(List *this) {
  this->capacity *= 2;

  int *arr = (int *)malloc(this->capacity * sizeof(int));

  for (int i = 0; i < this->size; i++) {
    arr[i] = (this->array)[i];
  }

  free(this->array);
  this->array = arr;
  arr = NULL;
  free(arr);
}

List *NewList() {
  List *list = (List *)malloc(sizeof(list));
  list->length = -1;
  list->capacity = 0;
  list->size = 0;
  return list;
}

void DestroyList(List *this) {
  this->length = -1;
  this->capacity = 0;
  this->size = 0;
  free(this);
}

void Append(List *this, int value) {
  this->size += 1;
  this->length += 1;
  if (this->capacity == 0) {
    this->capacity = 2;
    this->array = malloc(this->capacity * sizeof(int));
  }
  if (this->capacity == this->size) {
    AllocMemory(this);
  }
  this->array[this->length] = value;
}

void Prepend(List *this, int value) {
  this->length += 1;
  this->size += 1;
  if (this->capacity == 0) {
    this->capacity = 2;
    this->array = malloc(this->capacity * sizeof(int));
  } else if (this->capacity == this->size) {
    AllocMemory(this);
  }
  for (int i = this->length; i > 0; i--) {
    (this->array)[i] = (this->array)[i - 1];
  }
  (this->array)[0] = value;
}

void AppendAll(List *this, const List *that) {
  if ((this->capacity - this->size) < that->size) {
    AllocMemory(this);
  }
  for (int i = 0; i < that->size; i++) {
    this->length += 1;
    this->size += 1;
    this->array[this->length] = that->array[i];
  }
}

void InsertAt(List *this, int index, int value) {
  this->length += 1;
  this->size += 1;
  if (this->capacity == this->size) {
    AllocMemory(this);
  }
  for (int i = this->length; i > index; i--) {
    (this->array)[i] = (this->array)[i - 1];
  }
  (this->array)[index + 1] = value;
}

void RemoveAt(List *this, int index) {
  this->length -= 1;
  this->size -= 1;
  for (int i = index; i < this->size; i++) {
    (this->array)[i] = (this->array)[i + 1];
  }
  if (this->capacity >= this->size * 4) {
    MicroMemory(this);
  }
}

void RemoveAll(List *this) {
  this->length = 0;
  this->capacity = 0;
  this->size = 0;
  free(this);
}

int Pop(List *this) {

  int x = this->array[this->length];

  this->length -= 1;
  this->size -= 1;
  if (this->capacity >= this->size * 4) {
    MicroMemory(this);
  }

  return x;
}

int Dequeue(List *this) {
  int x = this->array[0];

  this->length -= 1;
  this->size -= 1;

  for (int i = 0; i < this->size; i++) {
    (this->array)[i] = (this->array)[i + 1];
  }

  if (this->capacity >= this->size * 4) {
    MicroMemory(this);
  }
  return x;
}

int Length(const List *this) { return this->size; }
int GetAt(const List *this, int index) { return this->array[index]; }

// this->array[this->size] == NULL