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

// void test_shared() {
//  shared_ptr<foo> foo_shptr(new foo{888, 999});
//  shared_ptr<foo> foo_shptr2 = foo_shptr;
//  assert(foo_shptr.get() == foo_shptr2.get());
//  std::cout << foo_shptr->field1 << " " << foo_shptr2->field1 << std::endl;

// плохое использование
// приводи к двойному удалению, так как теперь два умных указателя
// "владеют" одним обхектом, не зная друг о друге
//  shared_ptr<foo> foo_shptr3(foo_shptr2.get());
/**
Тут выпадет segfault:

smart_pointer_2(2642,0x1180fddc0) malloc: *** error for object 0x7fe322504080: pointer being freed was not allocated
smart_pointer_2(2642,0x1180fddc0) malloc: *** set a breakpoint in malloc_error_break to debug
**/
// }

static void test_shared_ptr() {
  //  static_assert(!std::is_convertible<int *, shared_ptr<int>>::value,
  //                "shared ptr should not have implicit constructor from pointer!");
  //
  //  static_assert(std::is_same<shared_ptr<int>::element_type, int>::value, "shared ptr should contain element_type");
  //
  //  static_assert(std::is_constructible<bool, shared_ptr<int>>::value  // explicit conversion
  //                    && !std::is_convertible<shared_ptr<int>,
  //                                            bool>::value,  // implicit conversion
  //                "shared ptr should convertible to the bool, but not implicitly");

  {
    shared_ptr<int> empty_ptr;

    assert(!empty_ptr);
    assert(empty_ptr.get() == nullptr);
  }

  {
    struct entity {
      int f1;
      std::string f2;
    };

    //  static_assert(std::is_same<shared_ptr<entity>::element_type, entity>::value,
    //  "shared ptr should contain element_type");

    shared_ptr<entity> const ptr{new entity{10, "hello"}};

    assert(ptr->f1 == 10);
    assert(ptr->f2 == "hello");

    assert((*ptr).f1 == 10);
    assert((*ptr).f2 == "hello");

    // TODO(Nariman): Почему равны мы же передаем адресс
    assert(ptr.get()->f1 == 10);
    assert(ptr.get()->f2 == "hello");
  }

  {
    shared_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.reset();
    assert(ptr.get() == nullptr);
    assert(!ptr);

    ptr.reset(new int{20});
    assert(*ptr == 20);
  }

  {
    shared_ptr<int> ptr{new int{10}};

    ptr = static_cast<shared_ptr<int> const &>(ptr);

    {
      shared_ptr<int> other{ptr};

      assert(other.get() == ptr.get());
      //  assert(&(*other) == &(*ptr));
    }

    {
      shared_ptr<int> other;

      other = ptr;

      assert(other.get() == ptr.get());
      //  assert(&(*other) == &(*ptr));
    }
  }

  {
    shared_ptr<int> first{new int{10}};
    shared_ptr<int> second{first};

    first.reset();
    // TODO(Nariman): Почему?
    assert(first.get() != second.get());

    first = second;
    assert(first.get() == second.get());

    second.reset(new int{20});
    assert(first.get() != second.get());

    second = first;
    assert(first.get() == second.get());
  }

  {
    struct A {
      int *a_;
      explicit A(int *a) : a_(a) {}
      virtual ~A() {
        *a_ = 0;
      }
    };

    int trigger = 42;
    {
      shared_ptr<A> first{new A{&trigger}};
      auto second = first;
      auto third = second;
      auto fourth = third;
      auto fifth = second;

      assert(first.get() == first.get());
      assert(*first->a_ == 42);
      assert(*fifth->a_ == 42);
    }
    //  assert(trigger == 0);
  }
}

// void bar() {
//  scoped_ptr<foo> foo_ptr(new foo{0, 111});
//  std::cout << (*foo_ptr).field1 << foo_ptr->field1 << foo_ptr.Get() << std::endl;
//
//  if (foo_ptr) foo_ptr->field1 += 1;
//
//  cout << foo_ptr.Get() << endl;
//  cout << foo_ptr->field1 << endl;

//  foo_ptr = std::move(foo_ptr);  // - compilation fails
//  auto foo_ptr2(foo_ptr);        // - compilation fails
//  foo_ptr = foo_ptr;             // - compilation fails
// bool status = foo_ptr;        // - compilation fails
//  }  //  foo_ptr уничтожен. Оператор delete вызван автоматически.

int main() {
  //  test_scoped();
  //  bar();
  // test_shared();
  //  test_scoped_ptr();
  test_shared_ptr();
  return 0;
}

/*Questions:
 * Почему realese не имеет смысла
 * T& operator*() const { *ptr_; } почему возращать именно ссылку, а не
 *Если придет пустой указатель, count должен быть равен 0
 *
 *
 * */
