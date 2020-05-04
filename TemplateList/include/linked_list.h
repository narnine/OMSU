#pragma once
#include <cstdlib>
#include <initializer_list>
#include <iostream>
template <typename T> struct Node {
  T value_;
  struct Node *next_;
};

template <typename T> class LinkedList {
private:
  Node<T> *head_ = nullptr;
  Node<T> *tail_ = nullptr;

public:
  explicit LinkedList(Node<T> *head = nullptr, Node<T> *tail = nullptr)
      : head_(head), tail_(tail) {}

  LinkedList<T>(std::initializer_list<T> elements) {
    for (auto &element : elements) {
      Append(element);
    }
  }
  LinkedList<T>(const LinkedList<T> &other) { AppendAll(&other); }

  LinkedList<T> &operator=(const LinkedList<T>) = delete;

  void Printf() {
    Node<T> *ptr = head_;

    if (ptr == nullptr) {
      std::cout << "ERROR" << std::endl;
    }
    for (int i = 1; ptr != nullptr; i++) {
      std::cout << ptr->value_ << std::endl;
      ptr = ptr->next_;
    }
    std::cout << std::endl;
  }

  void Append(int value) {
    Node<T> *new_node = new Node<T>;
    new_node->value_ = value;
    new_node->next_ = nullptr;
    if (head_ == nullptr) {
      head_ = new_node;
    } else {
      tail_->next_ = new_node;
    }
    tail_ = new_node;
    //  new_node = nullptr;
    //  delete new_node;
  }

  void Prepend(T value) {
    Node<T> *new_node = new Node<T>;
    new_node->value_ = value;
    if (head_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_ = new_node;
    }
  }

  void InsertAt(T index, T value) {
    if (index > Length()) {
      exit(-1);
    } else if (Length() == -1) {
      Append(value);
    } else {
      Node<T> *new_node = new Node<T>;
      new_node->value_ = value;
      Node<T> *ptr = head_;
      for (int i = 0; ptr != nullptr && i < index; i++) {
        ptr = ptr->next_;
      }
      new_node->next_ = ptr->next_;
      ptr->next_ = new_node;
      ptr = nullptr;
      delete ptr;
    }
  }

  void AppendAll(const LinkedList<T> *that) {
    Node<T> *node = that->head_;
    while (node != nullptr) {
      Append(node->value_);
      node = node->next_;
    }
  }
  void RemoveAt(T index) {
    if (head_ == nullptr || index <= -1) {
      exit(-1);
    } else {
      Node<T> *ptr = head_;
      Node<T> *node_index = nullptr;

      for (int i = 0; ptr != nullptr && i < index - 1; i++) {
        ptr = ptr->next;
      }

      node_index = ptr->next_;
      ptr->next = ptr->next->next;
      delete node_index;
    }
  }

  void RemoveAll() {
    Node<T> *current = head_;
    while (current != nullptr) {
      current = current->next;
      delete head_;
      head_ = current;
    }
    tail_ = nullptr;
  }

  T Pop() {
    if (head_ == nullptr) {
      return -1;
    }
    Node<T> *ptr = head_;

    for (int i = 0; ptr->next_ != tail_; i++) {
      ptr = ptr->next;
    }

    int a = tail_->value;
    delete tail_;
    ptr->next_ = nullptr;
    tail_ = ptr; /*Выделять памяять занова для this->tail?*/
    return a;
  }

  T Dequeue() {
    Node<T> *first = head_;
    head_ = head_->next_;
    T a = first->value;
    delete first;
    return a;
  }

  int Length() {
    int a = 1;
    Node<T> *ptr = head_;

    if (ptr == nullptr) {
      return 0;
    }

    for (int i = 1; ptr->next_ != nullptr; i++) {
      ptr = ptr->next_;
      a += 1;
    }

    return a;
  }

  T &operator[](size_t index) {
    if (index + 1 > Length()) {
      printf("ERROR: segmentation fault");
      exit(-1);
    }
    int c = 0;
    Node<T> *tmp = head_;
    while (c != index) {
      tmp = tmp->next_;
      c++;
    }
    return tmp->value_;
  }

  T *begin() { return head_; }
  T *end() { return tail_; }

  //  T &operator++(T*)

  virtual ~LinkedList<T>() { delete head_; }
};