#pragma once

#include <iostream>

// void assert(T a, T b) {
//  if (a != b) {
//    std::cout << "ERROR" << std::endl;
//    exit(-1);
//  }
//}

template<typename T>
class scoped_ptr {
 private:
  T *ptr_;

 public:
  typedef T element_type;

  explicit scoped_ptr(T *ptr = NULL) : ptr_(ptr) {}

  scoped_ptr(const scoped_ptr &scopedptr) = delete;

  scoped_ptr &operator=(const scoped_ptr &) = delete;

  T *Get() const {
    return ptr_;
  }

  T &operator*() const {
    return *ptr_;
  }

  T *operator->() const {
    return ptr_;
  }

  void reset(T &p1 = NULL, T &p2 = NULL) {
    if (p1 & p2) {
      p2 = p1;
    }
    delete p1;
  }

  T *release(T &ptr = NULL) {
    if (ptr) {
      auto a = ptr_;
      ptr_ = NULL;
      return a;
    }
  }

  // TODO(Nariman):
  explicit operator bool() const {
    return ptr_ != NULL;
  }

  ~scoped_ptr() {
    std::cout << "~ScoredPtr" << std::endl;
    delete ptr_;
  }
};
