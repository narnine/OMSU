#include "list.h"
#include <stdio.h>
#include <stdlib.h>
// В узле списка хранится само значение value и указатель на следующий узел.
// Эту структуру пользователи списка не должны видеть, так как она относится к
// внутренней реализации.
typedef struct Node_ {
  int value; // само значение, которое хранит узел
  struct Node_ *next; // указатель на следующий узел
} Node;

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  Node *head; // указатель на голову списка
  Node *tail; // указатель на хвост списка
  // если нужно, то добавьте дополнительные поля
};

void Printf(List *this) {
  Node *ptr = this->head;

  if (ptr == NULL) {
    printf("%d ", -1);
  }

  for (int i = 1; ptr != NULL; i++) {
    printf("%d ", (ptr->value)); //почему не разыминованием?
    ptr = ptr->next;
  }
  printf("\n");
}

List *NewList() {
  List *list =
      (List *)malloc(sizeof(List)); //Забыл зачем указатели почему нам просто не
                                    //бахнуть лист на стеке ыыы?
  list->head = NULL;
  list->tail = NULL;

  return list;
}

void DestroyList(List *this) {
  Node *next = NULL;
  Node *current = this->head;
  //Почему не созда для current и next память черзе malloc - это глупо так
  //пройзойдет перезаполнение, а выделеная пать так и будет висеть?
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(this->head);
  free(this);
}

int Length(const List *this);

void Append(List *this, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  if (this->head == NULL) {
    this->head = new_node;
  } else {
    (this->tail)->next = new_node;
  }
  this->tail = new_node;
}

void Prepend(List *this, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  if (this->head == NULL) {
    this->head = new_node;
    this->tail = new_node;
  } else {
    new_node->next = this->head;
    this->head = new_node;
  }
}

void AppendAll(List *this, List *that) {
  this->tail->next = that->head;
  this->tail = that->tail;
  that->head = NULL;
  that->tail = NULL;
  DestroyList(that);
}

void InsertAt(List *this, int index, int value) {
  if (index > Length(this)) {
    exit(-1);
  } else if (Length(this) == -1) {
    Append(this, value);
  } else {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    Node *ptr = this->head;

    for (int i = 0; ptr != NULL && i < index; i++) {
      ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
  }
}

void RemoveAt(List *this, int index) {
  if (this->head == NULL || index <= -1) {
    exit(-1);
  } else if (Length(this) == 0) {
    free(this->head);
    this->head = NULL;
    this->tail = NULL;
  } else {
    Node *ptr = this->head;
    Node *node_index = NULL;

    for (int i = 0; ptr != NULL && i < index - 1; i++) {
      ptr = ptr->next;
    }

    node_index = ptr->next;
    ptr->next = ptr->next->next;
    free(node_index);
  }
}

void RemoveAll(List *this) {
  Node *current = this->head;
  while (current != NULL) {
    current = current->next;
    free(this->head);
    this->head = current;
  }
  this->tail = NULL;
}

int Pop(List *this) {
  if (this->head == NULL) {
    return -1;
  }
  Node *ptr = this->head;

  for (int i = 0; ptr->next != this->tail; i++) {
    ptr = ptr->next;
  }

  Node *last = this->tail;
  free(this->tail);
  ptr->next = NULL;
  this->tail = ptr; /*Выделять памяять занова для this->tail?*/
  int a = last->value;
  free(last);
  return a;
}

int Dequeue(List *this) {
  Node *first = this->head;
  free(this->head);
  this->head = first->next;
  int a = first->value;
  free(first);
  return a;
}

int Length(const List *this) {
  int a = 1;
  Node *ptr = this->head;

  if (ptr == NULL) {
    return 0;
  }

  for (int i = 1; ptr->next != NULL; i++) {
    ptr = ptr->next;
    a += 1;
  }

  return a;
}

int GetAt(const List *this, int index) {
  if (index > Length(this)) {
    return -1;
  } else {
    Node *ptr = this->head;
    for (int i = 0; ptr != NULL && i < index; i++) {
      ptr = ptr->next;
    }
    return ptr->value;
  }
}
