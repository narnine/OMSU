#pragma once

#include <iostream>
template <typename T>

class ScopedPtr {
private:
  T *ptr_;

public:
  explicit ScopedPtr(T *ptr) : ptr_(ptr) {}

  T *Get() const { return ptr_; }

  T& operator*() const { *ptr_; }
  //  TODO(Nariman)
  void reset(T *p) {}
  ~ScopedPtr() { std::cout << "~ScoredPtr" << std::endl; }
};
