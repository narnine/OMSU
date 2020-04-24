#include <cassert>
#include <iostream>

#include "include/scoped_ptr.h"
#include "include/shared_ptr.h"
#include "string"
using namespace std;
// void test_scoped() {
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

void test_shared(){
  
}

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

static void test_scoped_ptr() {
  static_assert(!std::is_convertible<int *, scoped_ptr<int>>::value,
                "scoped ptr should not have implicit constructor from pointer!");

  static_assert(!std::is_copy_constructible<scoped_ptr<int>>::value, "scoped ptr should not be copiable");

  static_assert(!std::is_move_constructible<scoped_ptr<int>>::value, "scoped ptr should not be movable");

  static_assert(!std::is_copy_assignable<scoped_ptr<int>>::value, "scoped ptr should not be copiable by operator=");

  static_assert(!std::is_move_assignable<scoped_ptr<int>>::value, "scoped ptr should not be movable by operator=");

  static_assert(std::is_same<scoped_ptr<int>::element_type, int>::value, "scoped ptr should contain element_type");

  static_assert(std::is_constructible<bool, scoped_ptr<int>>::value  // explicit conversion
                    && !std::is_convertible<scoped_ptr<int>,
                                            bool>::value,  // implicit conversion
                "scoped ptr should convertible to the bool, but not implicitly");

  {
    scoped_ptr<int> empty_ptr;

    assert(!empty_ptr);
    assert(empty_ptr.Get() == nullptr);
  }

  {
    struct entity {
      int f1;
      std::string f2;
    };

    static_assert(std::is_same<scoped_ptr<entity>::element_type, entity>::value,
                  "scoped ptr should contain element_type");

    scoped_ptr<entity> const ptr{new entity{10, "hello"}};

    assert(ptr->f1 == 10);
    assert(ptr->f2 == "hello");

    assert((*ptr).f1 == 10);
    assert((*ptr).f2 == "hello");

    assert(ptr.Get()->f1 == 10);
    assert(ptr.Get()->f2 == "hello");
  }

  {
    scoped_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.Reset();
    assert(ptr.Get() == nullptr);
    assert(!ptr);

    ptr.Reset(new int{20});
    assert(*ptr == 20);
  }

  {
    int *i = new int{10};
    scoped_ptr<int> ptr{i};

    assert(i == ptr.release());

    delete i;
  }
}

int main() {
  //  test_scoped();
  test_shared();
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
 * Про reset
 *
 *
 * */
