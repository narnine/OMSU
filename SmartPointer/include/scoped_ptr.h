#pragma once

#include <iostream>

template<typename T>
class scoped_ptr {
 private:
  T *ptr_;

 public:
  typedef T element_type;

  explicit scoped_ptr(T *ptr = NULL) : ptr_(ptr) {}

  scoped_ptr(const scoped_ptr &scopedptr) = delete;

  scoped_ptr &operator=(const scoped_ptr &) = delete;

  scoped_ptr(scoped_ptr &&x) = delete;

  T *Get() const {
    return ptr_;
  }

  T &operator*() const {
    return *ptr_;
  }

  T *operator->() const {
    return ptr_;
  }


  void Reset(T *other = NULL) {
    delete ptr_;
    ptr_ = other;
  }

  T *release(T *ptr = NULL) {
    auto a = ptr_;
    ptr_ = NULL;
    return a;
  }

  explicit operator bool() const {
    return ptr_ != NULL;
  }

  ~scoped_ptr() {
    std::cout << "~ScoredPtr" << std::endl;
    delete ptr_;
  }
};
