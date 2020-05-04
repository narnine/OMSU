#include "include/array_list.h"
//  #include "include/linked_list.h"
#include "vector"
#include <bits/unique_ptr.h>
#include <iostream>

using namespace std;

static void AssertEq(int expected, int actual, const char *msg) {
  if (expected != actual) {
    cout << "Test failed: %s\n expected %d but got %d\n"
         << ", " << msg << ", " << expected << ", " << actual << endl;
    exit(-1);
  }
}

 void test_with_unique() {
  std::vector<std::unique_ptr<int>> v;
  v.push_back(std::make_unique<int>(12));
  *v.at(0).get() = 12;
  auto p1 = std::make_unique<int>(42);
  auto p2 = std::make_unique<int>(62);
  ArrayList<std::unique_ptr<int>> list={std::make_unique<int>(62)};
}

//  void test_array_list() {
//  ArrayList<int> list = {1, 2};
//  list.Print();
//  list.Append(3);
//
//  for (auto &element : list) {
//    cout << element << " ";
//  }
//
//  for (auto el = list.begin(); el != list.end(); el++) {
//    cout << *el << " ";
//  }
//
//  ArrayList<int> list_two = {1, 2, 3, 4};
//
//  list.Append(12);
//  AssertEq(4, list.GetLength(), "empty list length should be zero");
//
//  list.Prepend(0);
//  AssertEq(5, list.GetLength(), "empty list length should be zero");
//
//  list.Pop();
//  AssertEq(4, list.GetLength(), "empty list length should be zero");
//}

//void test_linked_list() {
//  LinkedList<int> list;
//  list.Append(42);
//  AssertEq(1, list.Length(), "empty list length should be zero");
//  //  for (auto &element : list) {
//  //    cout << element << " ";
//  //  }
//  //  cout << endl;
//  list.Printf();
//
//  LinkedList<int> list_two = {1, 2, 3};
//  AssertEq(3, list_two.Length(), "empty list length should be zero");
//
  // Check AppendAll
  //  list.Printf();
  //  list_two.Printf();
  //  list.AppendAll(&list_two);
  //  list.Printf();
  //  list_two.Printf();

  // Check Prepend
//  AssertEq(1, list.Length(), "empty list length should be zero");
//  list.Prepend(62);
//  AssertEq(2, list.Length(), "empty list length should be zero");
//  list.Printf();
//
//  // Check Insert
//  AssertEq(2, list.Length(), "empty list length should be zero");
//  list.InsertAt(1,38);
//  AssertEq(3, list.Length(), "empty list length should be zero");
//  list.Printf();
//}

int main() {
  // test_array_list();
  //  test_linked_list();
  test_with_unique();
  //
  //    Prepend(list_two, 2);
  //    Append(list_two, 3);
  //    Append(list_two, 4);
  //    Append(list_two, 4);
  //    Printf(list);
  //    Printf(list_two);
  //    AppendAll(list, list_two);
  //    Printf(list);
  //    DestroyList(list_two);
  //    Printf(list);
  //    Printf(list_two);

  return 0;
}
/*Questions
 * Как сделать range based for
 * Почему написанно деструкторы
 *Конструктор копирования, оба объекта указывают на 1 массив или на 2 в
 *linkedlist Если придет не пустой массив в конструктор копирования Что лучше
 *сначала увеличивать index, а потом вставлять или наоборот? Chat Coding Garden
 * */
