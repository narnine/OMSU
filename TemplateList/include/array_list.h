#pragma once
#include "cassert"
#include "iterator"
#include <bits/unique_ptr.h>
#include <iostream>

template <typename T> class ArrayList {
private:
  T *array_{};
  size_t capacity_ = 0;
  size_t length_ = -1;

  void ReallocateAndMove(int capacity) {
    capacity_ = capacity;
    auto new_buf = static_cast<T *>(::operator new(sizeof(T) * capacity_));

    for (int i = 0; i < length_ + 1; i++) {
      ::new (new_buf + i)
          T(std::move(array_[i])); // TODO(Nariman): Move сразу удаляет из
                                   // памяти объект сам?
      array_[i].~T(); // old object "wrapper" should be deleted
    }

    ::operator delete(array_);
    array_ = new_buf; // TODO(Nariman): нужно ли удали new_buf?
  }

  void AllocateMemory() {
    if (length_ + 1 < capacity_)
      return;
    if (capacity_ == 0)
      capacity_ = 1; // edge case when empty array_

    // Mem growth: 0 2 4 8 16 ...
    // read more about how to allocate memory for vector or ArrayList
    ReallocateAndMove(capacity_ * 2);
  }

public:
  explicit ArrayList(size_t capacity = 2) : capacity_(capacity), length_(-1) {
    if (capacity_ < 2) {
      capacity_ = 2;
    }
    array_ = static_cast<T *>(::operator new(sizeof(T) * capacity_));
  }

  ArrayList<T>(std::initializer_list<T> &elements) {
    length_ = -1;
    capacity_ = elements.size() * 2;
    array_ = new T[capacity_];
    for (auto &element : elements) {
      length_++;
      array_[length_] = element;
    }
  }

  // TODO(Nariman): HOW
  ArrayList<T>(std::initializer_list<T> &&elements) {
    length_ = -1;
    capacity_ = elements.size() * 2;
    array_ = static_cast<T *>(::operator new(sizeof(T) * capacity_));
    for (auto &element : elements) {
      length_++;
      ::new (array_ + length_) T(std::move(element));
    }
  }

  ArrayList<T>(const ArrayList<T> &other) {
    capacity_ = other.capacity_;
    length_ = other.length_;
    array_ = new T[capacity_];
    for (int i = 0; i < length_ + 1; i++) {
      array_[i] = other.array_[i];
    }
  }
  // TODO(Nariman): constructive copy and =
  ArrayList<T> &operator=(const ArrayList<T> &other) {
    if (this != &other) {
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
    return *this;
  }

  void DestroyList() {
    capacity_ = 0;
    length_ = -1;
    ::operator delete(array_);
    array_ = nullptr;
  }

  void Append(const T &value) {
    length_++;
    AllocateMemory();
    ::new (array_ + length_) T(value);
  }

  void Append(T &&value) {
    length_++;
    AllocateMemory();
    ::new (array_ + length_) T(std::move(value));
  }
  // TODO(Nariman): все падоло когда передавали const T value
  void Prepend(const T &value) {
    length_++;
    AllocateMemory();
    if (length_ != 0) {
      for (int i = length_; i > 0; i--) {
        array_[i] = array_[i - 1];
      }
    }
    array_[0] = value;
  }

  void Prepend(T &&value) {
    length_++;
    AllocateMemory();
    if (length_ != 0) {
      for (int i = length_; i > 0; i--) {
        ::new (array_ + i) T(std::move(array_[i - 1]));
      }
    }
    ::new (array_ + 0) T(std::move(value));
  }

  // TODO(Nariman): HOW
  void AppendAll(const ArrayList<T> &that) {
    AllocateMemory();
    for (int i = 0; i < that.length_ + 1; i++) {
      length_++;
      ::new (array_ + length_) T(std::move(that.array_ + i));
    }
  }

  void InsertAt(int index, const T &value) {
    length_ += 1;
    if (index < 0) {
      std::cout << "ERROR: INDEX CAN NOT BE NEGATIVE NUMBER" << std::endl;
      exit(-1);
    }
    if (capacity_ == 0 || capacity_ <= length_ + 1) {
      AllocateMemory();
    }
    for (int i = length_; i > index + 1; i--) {
      array_[i] = array_[i - 1];
    }
    array_[index + 1] = value;
  }

  void InsertAt(int index, T &&value) {
    length_ += 1;
    if (index < 0) {
      std::cout << "ERROR: INDEX CAN NOT BE NEGATIVE NUMBER" << std::endl;
      exit(-1);
    }
    AllocateMemory();
    for (int i = length_; i > index + 1; i--) {
      ::new (array_ + i) T(std::move(array_[i - 1]));
    }
    ::new (array_ + index + 1) T(std::move(value));
  }

  void RemoveAt(int index) {
    length_--;
    if (index < 0) {
      std::cout << "ERROR: INDEX CAN NOT BE NEGATIVE NUMBER" << std::endl;
      exit(-1);
    }
    if (capacity_ == 0 || length_ < 0) {
      std::cout << "ERROR" << std::endl;
      exit(-1);
    }
    for (int i = index; i < length_ + 1; i++) {
      array_[i].~T(); // TODO(Nariman) : мы чистим умный указаетль
      ::new (array_ + i) T(std::move(array_[i + 1]));
    }
    if (capacity_ >= (length_ + 1) * 4) {
    }
  }

  void RemoveAll() {
    length_ = -1;
    capacity_ = 0;
    free(array_);
  }

  T Pop() {
    T x = T(std::move(array_[length_]));
    array_[length_].~T();
    length_--;

    // MicroMemory();
    return x;
  }

  T Dequeue() {
    T x = T(std::move(array_[0]));
    array_[0].~T();

    length_--;

    for (int i = 0; i < length_ + 1; i++) {
      ::new (array_ + i) T(std::move(array_[i + 1]));
    }

    //  MicroMemory();
    return x;
  }

  int GetLength() { return length_ + 1; }
  int GetCapacity() { return capacity_; }

  void SetSize(int new_size) { length_ = new_size; }
  void SetCapacity(int new_capacity) { capacity_ = new_capacity; }

  const T &At(int index) const {
    assert(index >= 0 && index < length_ + 1);
    return array_[index];
  }

  // TODO(Nariman): работу с некопируемыми типами
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
    std::cout << "~ArrayList" << std::endl;
    for (int i = 0; i < length_; i++) {
      array_[i].~T();
    }

    ::operator delete(array_);
    array_ = nullptr;
    capacity_ = 0;
    length_ = 0;
  }
};
