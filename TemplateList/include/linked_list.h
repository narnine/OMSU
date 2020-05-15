#pragma once
#include <bits/unique_ptr.h>
#include <cstdlib>
#include <initializer_list>
#include <iostream>

namespace linkedlist {
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

  LinkedList<T>(std::initializer_list<T> &elements) {
    for (auto &element : elements) {
      // Append(element);
    }
  }

  // TODO(Nariman) : How
  LinkedList<T>(std::initializer_list<T> &&elements) {
    for (auto &element : elements) {
    }
  }

  LinkedList<T>(const LinkedList<T> &other) { AppendAll(&other); }

  LinkedList<T> &operator=(const LinkedList<T>) = delete;

  class iterator {
    Node<T> *node_ = nullptr;

  public:
    typedef T value_type;
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;

    // конструктор
    explicit iterator(Node<T> *node) : node_(node) {}

    //++a
    iterator &operator++() {
      node_ = node_->next_;
      return *this;
    }

    // a++
    iterator operator++(int junk) {
      iterator res = *this;
      ++(*this);
      return res;
    }

    T &operator*() { return node_->value_; }
    T *operator->() { &(node_->value_); }
    bool operator==(const iterator &rhs) { return (node_ == rhs.node_); }
    bool operator!=(const iterator &rhs) { return (node_ != rhs.node_); }
  };

  void Printf() {
    Node<T> *ptr = head_;

    if (ptr == nullptr) {
      std::cout << "ERROR" << std::endl;
    }
    for (int i = 1; ptr != nullptr; i++) {
      std::cout << *ptr << std::endl;
      ptr = ptr->next_;
    }
    std::cout << std::endl;
  }

  void Append(T &value) {
    Node<T> *new_node = new Node<T>;
    new_node->value_ = value;
    new_node->next_ = nullptr;
    if (head_ == nullptr) {
      head_ = new_node;
    } else {
      tail_->next_ = new_node;
    }
    tail_ = new_node;
  }

  void Append(T &&value) {
    Node<T> *new_node = static_cast<Node<T> *>(::operator new(sizeof(T)));
    ::new (new_node) T(std::move(value));
    new_node->next_ = nullptr;
    if (head_ == nullptr) {
      head_ = new_node;
    } else {
      tail_->next_ = new_node;
    }
    tail_ = new_node;
  }

  void Prepend(const T &value) {
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

  void Prepend(T &&value) {
    Node<T> *new_node = static_cast<Node<T> *>(::operator new(sizeof(T)));
    ::new (new_node) T(std::move(value));
    if (head_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_ = new_node;
    }
  }

  void InsertAt(int index, const T &value) {
    if (index > Length()) {
      exit(-1);
    } else if (Length() == -1) {
      Append(value);
    } else {
      Node<T> *new_node = new Node<T>;
      new_node->value_ = value;
      Node<T> *ptr = head_;
      for (int i = 0; ptr != nullptr && i < index + 1; i++) {
        ptr = ptr->next_;
      }
      new_node->next_ = ptr->next_;
      ptr->next_ = new_node;
      ptr = nullptr;
      delete ptr;
    }
  }

  void InsertAt(int index, T &&value) {
    if (Length() == 0) {
      Append(std::move(value));
    } else {
      Node<T> *new_node = static_cast<Node<T> *>(::operator new(sizeof(T)));
      ::new (new_node) T(std::move(value));
      Node<T> *ptr = head_;
      for (int i = 0; ptr != nullptr && i < index + 1; i++) {
        ptr = ptr->next_;
      }
      new_node->next_ = ptr->next_;
      ptr->next_ = new_node;
      ptr = nullptr;
      delete ptr;
    }
  }

  void AppendAll(const LinkedList<T> &that) {
    Node<T> *node = that.head_;
    while (node != nullptr) {
      Append(std::move(node->value_));
      node = node->next_;
    }
  }

  void RemoveAt(int index) {
    if (head_ == nullptr || index <= -1) {
      exit(-1);
    } else {
      Node<T> *ptr = head_;
      Node<T> *node_index = nullptr;

      for (int i = 0; ptr != nullptr && i < index - 1; i++) {
        ptr = ptr->next_;
      }

      node_index = ptr->next_;
      ptr->next_ = ptr->next_->next_;
      node_index->value_.~T();
      node_index->next_ = nullptr;
    }
  }

  void RemoveAll() {
    Node<T> *current = head_;
    while (current != nullptr) {
      current = current->next_;
      head_->value_.~T();
      head_ = current;
    }
    tail_ = nullptr;
  }

  T Pop() {
    if (head_ == nullptr) {
      exit(-1);
    }
    Node<T> *ptr = head_;

    for (int i = 0; ptr->next_ != tail_; i++) {
      ptr = ptr->next_;
    }

    T a = T(std::move(tail_->value_));
    tail_->value_.~T();
    ptr->next_ = nullptr;
    tail_ = ptr; /*Выделять памяять занова для this->tail?*/
    return a;
  }

  T Dequeue() {
    Node<T> *first = head_;
    head_ = head_->next_;
    T a = std::move(first->value_);
    first->value_.~T();
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

  iterator begin() { return iterator(head_); }
  iterator end() { return iterator(tail_->next_); }

  //  T &operator++(T*)

  virtual ~LinkedList<T>() { delete head_; }
};
} // namespace linkedlist