#pragma once

template<typename T>
class shared_ptr {
 private:
  T* ptr_;
  int* count_;

 public:
  typedef T element_type;
  explicit shared_ptr(T* ptr = NULL) : ptr_(ptr), count_(new int{1}) {}

  shared_ptr(const shared_ptr& sharedptr) {
    ptr_ = sharedptr.ptr_;
    count_ = sharedptr.count_;
    (*count_)++;
  }

  shared_ptr& operator=(const shared_ptr& sharedptr) {
    if (this != &sharedptr) {
      *count_ --;
      ptr_ = sharedptr.ptr_;
      count_ = sharedptr.count_;
      *count_++;
    }
    return *this;
  }

  T* get() const {
    return ptr_;
  };

  T* operator->() const {
    return ptr_;
  }

  T operator*() const {
    return *ptr_;
  }

//  T operator&() const {
//    return ptr_;
//  }

  void reset(T* other = nullptr) {
    ptr_ = NULL;
    delete ptr_;
    ptr_ = other;
  }

  explicit operator bool() const {
    return ptr_ != NULL;
  }

  virtual ~shared_ptr() {
    std::cout << "~sharedptr" << std::endl;
    if (count_ == 0) {
      delete ptr_;
      delete count_;
    } else {
      ptr_ = NULL;
      delete ptr_;
      *count_ -= 1;
    }
  }
};