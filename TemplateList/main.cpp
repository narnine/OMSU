#include <iostream>

template <typename T> class ArrayList {
private:
  T *array_;
  size_t capacity_;
  size_t size_;
  ArrayList(T *array, size_t capacity, size_t size)
      : array_(array), capacity_(capacity), size_(size) {}

public:
  static ArrayList<T> of(std::initializer_list<T> elements) {
    for (auto &element : elements) {
    }
  }

  T &operator[](size_t index) {}

  ~ArrayList() { std::cout << "~ScoredPtr" << std::endl; }
};

class LinkedList {};

int main() {
  // ArrayList<int> list = {1,2};
  return 0;
}
/*Questions
 *про конструктор: как он должен выглядеть, иногда мы пишем через :
 * */
