#pragma once
template <typename T> struct Node {
  T value_;
  struct Node *next_;
};

template <typename T> class LinkedList {
private:
  Node<T> *head_;
  Node<T> *tail_;

public:
  LinkedList<T>(std::initializer_list<T> elements) {}

  void Printf() {
    Node<T> *ptr = head_;

    if (ptr == NULL) {
      printf("%d ", -1);
    }
    for (int i = 1; ptr != NULL; i++) {
      printf("%d ", (ptr->value_));
      ptr = ptr->next_;
    }
    printf("\n");
  }

  void Append(int value) {
    Node<T> *new_node = (Node<T> *)malloc(sizeof(Node<T>));
    new_node->value_ = value;
    new_node->next_ = NULL;

    if (head_ == NULL) {
      head_ = new_node;
    } else {
      tail_->next_ = new_node;
    }
    tail_ = new_node;
  }

  virtual ~LinkedList<T>() {
    delete head_;
    delete tail_;
  }
};