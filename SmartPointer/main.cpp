#include <iostream>

#include "include/scoped_ptr.h"
#include "string"
using namespace std;
// void test_0() {
//  scoped_ptr<int> scopedptr(new int(5));
//  int *a = scopedptr.Get();
//  assert(*a, 5);
//  *scopedptr = 33;
//  assert(*scopedptr, 33);
//  //  assert(scopedptr->a, 33);
//  //  scoped_ptr<int> scored(scopedptr);
//}

struct foo {
  int field1;
  int field2;
};

void bar() {
  scoped_ptr<foo> foo_ptr(new foo{0, 111});
  std::cout << (*foo_ptr).field1 << foo_ptr->field1 << foo_ptr.Get() << std::endl;

  if (foo_ptr) foo_ptr->field1 += 1;

  cout << foo_ptr.Get() << endl;
  cout << foo_ptr->field1 << endl;

  //  foo_ptr = std::move(foo_ptr);  // - compilation fails
  //  auto foo_ptr2(foo_ptr);        // - compilation fails
  //  foo_ptr = foo_ptr;             // - compilation fails
  // bool status = foo_ptr;        // - compilation fails
}  //  foo_ptr уничтожен. Оператор delete вызван автоматически.

void sstatic_assert(bool a, string b = "") {
  if (a == true) {
    cout << "ERROR" << endl;
    exit(-1);
  }
}

void assert(bool a = 1, scoped_ptr &ptr = NULL) {
  if (!a) {
    std::cout << "ERROR" << std::endl;
    exit(-1);
  }
}

static void test_scoped_ptr() {
  {
    scoped_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.Reset();
    assert(ptr.Get() == nullptr);
    assert(!ptr);

    ptr.reset(new int{20});
    assert(*ptr == 20);
  }
}

int main() {
  //  test_0();
  //  bar();
  test_scoped_ptr();
  return 0;
}

/*Questions:
 *  T& operator*() const { *ptr_; } почему возращать именно ссылку, а не
 * указатель например
 * Почему не пишем this
 * Почему -> возращает значение, а Get адресс
 *Reset
 * Про конструкторы копирования и перемещения
 * typedef T element_type
 *
 *
 *
 * */
