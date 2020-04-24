#pragma once
template<typename T>
class shared_ptr {
  T* ptr_;

 public:
  typedef T element_type;
  explicit shared_ptr(T* ptr = NULL) : ptr_(ptr) {}

  T* get() const {
    return ptr_;
  }

  void reset(T* other = nullptr) {
    delete ptr_;
    ptr_ = other;
    other = NULL;
    delete other;
  }

  virtual ~shared_ptr() {
    std::cout << "~SharedPtr" << std::endl;
    delete ptr_;
  }
};