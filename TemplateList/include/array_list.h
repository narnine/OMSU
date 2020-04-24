#pragma once
#include "iterator"
#include <iostream>

template <typename T> class ArrayList {
private:
  T *array_;
  size_t capacity_;
  size_t length_;

  void AllocMemory() {
    if (capacity_ == 0) {
      capacity_ = 1;
    }

    capacity_ *= 2;

    ArrayList<T> new_list(capacity_);

    for (int i = 0; i < length_; i++) {
      new_list.array_[i] = array_[i];
    }
    free(array_);
    array_ = new_list.array_;
    new_list.array_ = NULL;
    free(new_list.array_);
  }

public:
  explicit ArrayList(size_t capacity = 0) : capacity_(capacity), length_(-1) {
    if (capacity_ == 0) {
      array_ = NULL;
    } else {
      array_ = new T[capacity_];
    }
  }

  ArrayList<T>(std::initializer_list<T> elements) {
    length_ = -1;
    capacity_ = elements.size() * 2;
    array_ = new T[capacity_];
    for (auto &element : elements) {
      length_++;
      array_[length_] = element;
    }
  }

  ArrayList<T>(const ArrayList<T> &other) {
    if (length_ != -1) {
      delete array_;
    }
    capacity_ = other.capacity_;
    length_ = other.length_;
    array_ = new T[capacity_];
    for (int i = 0; i < length_ + 1; i++) {
      array_[i] = other.array_[i];
    }
  }

  ArrayList<T> &operator=(const ArrayList<T> &other) {
    if (length_ != -1) {
      delete array_;
    }
    capacity_ = other.capacity_;
    length_ = other.length_;
    array_ = new T[capacity_];
    for (int i = 0; i < length_ + 1; i++) {
      array_[i] = other.array_[i];
    }
  }

  void DestroyList() {
    capacity_ = 0;
    length_ = -1;
    free(array_);
  }

  void Append(T value) {
    length_++;
    if (capacity_ == 0 || capacity_ <= length_ + 1) {
      AllocMemory();
    }
    array_[length_] = value;
  }

  void Prepend(T value) {
    length_++;
    if (capacity_ == 0 || capacity_ <= length_ + 1) {
      AllocMemory();
    }
    if (length_ != 0) {
      for (int i = length_; i > 0; i--) {
        array_[i] = array_[i - 1];
      }
    }
    array_[0] = value;
  }

  void AppendAll(const ArrayList<T> &that) {
    if (length_ + that.GetLength() + 2 >= capacity_) {
      AllocMemory();
    }
    for (int i = 0; i < that->size; i++) {
      length_++;
      array_[length_] = that.array_[i];
    }
  }

  void InsertAt(int index, T value) {
    length_ += 1;
    if (index < 0) {
      std::cout << "ERROR: INDEX CAN NOT BE NEGATIVE NUMBER" << std::endl;
      exit(-1);
    }
    if (capacity_ == 0 || capacity_ <= length_ + 1) {
      AllocMemory();
    }
    for (int i = length_; i > index; i--) {
      array_[i] = array_[i - 1];
    }
    array_[index + 1] = value;
  }

  void RemoveAt(int index) {
    length_ -= 1;
    if (index < 0) {
      std::cout << "ERROR: INDEX CAN NOT BE NEGATIVE NUMBER" << std::endl;
      exit(-1);
    }
    if (capacity_ == 0 || length_ < 0) {
      std::cout << "ERROR" << std::endl;
      exit(-1);
    }
    for (int i = index; i < length_ + 1; i++) {
      array_[i] = array_[i + 1];
    }
    if (capacity_ >= (length_ + 1) * 4) {
      //  MicroMemory();
    }
  }

  void RemoveAll() {
    length_ = -1;
    capacity_ = 0;
    free(array_);
  }

  T Pop() {
    T x = array_[length_];
    array_[length_] = 0;

    length_ -= 1;
    if (capacity_ >= (length_ + 1) * 4) {
      // MicroMemory();
    }

    return x;
  }

  T Dequeue() {
    T x = array_[0];
    array_[0] = 0;

    length_ -= 1;

    for (int i = 0; i < length_ + 1; i++) {
      array_[i] = array_[i + 1];
    }

    if (capacity_ >= (length_ + 1) * 4) {
      //  MicroMemory();
    }
    return x;
  }

  int GetLength() { return length_; }
  int GetCapacity() { return capacity_; }

  void SetSize(int new_size) { length_ = new_size; }
  void SetCapacity(int new_capacity) { capacity_ = new_capacity; }

  void Print() {
    for (int i = 0; i < GetLength() + 1; i++) {
      std::cout << array_[i] << " ";
      if (i == GetLength()) {
        std::cout << std::endl;
      }
    }
  }

  T &operator[](size_t index) { return array_[index]; }

  T *begin() { return array_; };
  T *end() { return array_ + length_ + 1; };

  ~ArrayList() {
    std::cout << "~ScoredPtr" << std::endl;
    delete array_;
  }
};
