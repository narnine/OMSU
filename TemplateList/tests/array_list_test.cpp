#include "../include/array_list.h"
#include <gtest/gtest.h>
//  #include "../include/linked_list.h"
#include "vector"
#include <bits/unique_ptr.h>


using namespace std;

// static void AssertEq(int expected, int actual, const char *msg) {
//  if (expected != actual) {
//    cout << "Test failed: %s\n expected %d but got %d\n"
//         << ", " << msg << ", " << expected << ", " << actual << endl;
//    exit(-1);
//  }
//}

TEST(ArrayList, arraylist_just_create_arr_Test) {
  ArrayList<std::unique_ptr<int>> arrayList;

}

//
// void test_questions() {
//  ArrayList<std::unique_ptr<int>> arrayList;
//  arrayList.Append(std::make_unique<int>(42));
//  assert(*arrayList.At(0).get() == 42);
//  arrayList.DestroyList();
//}

// void test_with_unique_array_list() {
//  //  std::vector<std::unique_ptr<int>> v;
//  //  v.push_back(std::make_unique<int>(12));
//  //  *v.at(0).get() = 12;
//  //  auto p1 = std::make_unique<int>(42);
//  //  auto p2 = std::make_unique<int>(62);
//  //  ArrayList<std::unique_ptr<int>> list = {std::make_unique<int>(62)};
//  ArrayList<std::unique_ptr<int>> arrayList;
//  arrayList.Append(std::make_unique<int>(42));
//  assert(*arrayList.At(0).get() == 42);
//  assert(arrayList.GetLength() == 1);
//
//  arrayList.Append(std::make_unique<int>(62));
//  assert(*arrayList.At(0).get() == 42);
//  assert(*arrayList.At(1).get() == 62);
//  assert(arrayList.GetLength() == 2);
//
//  arrayList.Prepend(std::make_unique<int>(9));
//  assert(*arrayList.At(0).get() == 9);
//  assert(*arrayList.At(1).get() == 42);
//  assert(arrayList.GetLength() == 3);
//
//  arrayList.InsertAt(1, std::make_unique<int>(27));
//  assert(*arrayList.At(0).get() == 9);
//  assert(*arrayList.At(1).get() == 42);
//  assert(*arrayList.At(2).get() == 27);
//  assert(arrayList.GetLength() == 4);
//
//  arrayList.RemoveAt(0);
//  assert(*arrayList.At(0).get() == 42);
//  assert(arrayList.GetLength() == 3);
//
//  ArrayList<std::unique_ptr<int>> arrayList2;
//  arrayList2.Append(std::make_unique<int>(0));
//  arrayList2.Append(std::make_unique<int>(2));
//  arrayList2.Append(std::make_unique<int>(4));
//
//  //  arrayList.AppendAll(arrayList2);
//
//
//  assert(*(arrayList2.Pop()) == 4);
//
//  //  ArrayList<std::unique_ptr<int>> arrayList3 =
//  {std::make_unique<int>(100)};
//}

// void test_with_unique_linked_list() {
//  LinkedList<std::unique_ptr<int>> linkedList;
//  linkedList.Append(std::make_unique<int>(4));
//  assert(*linkedList[0] == 4);
//  linkedList.Append(std::make_unique<int>(0));
//  linkedList.Append(std::make_unique<int>(2));
//  linkedList.Append(std::make_unique<int>(4));
//  linkedList.Append(std::make_unique<int>(8));
//  assert(*linkedList.Pop() == 8);
//}

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
//
//      AssertEq(12, list.Pop(), "empty list length should be zero");
//  AssertEq(4, list.GetLength(), "empty list length should be zero");
//}

// void test_linked_list() {
//  LinkedList<int> list;
//  list.Append(42);
//  list.Append(62);
//  list.Append(100);
//  AssertEq(3, list.Length(), "empty list length should be zero");
//  for (auto &element : list) {
//    cout << element << " ";
//  }
//  cout << endl;
//  list.Printf();
//
//  auto a = list.begin();
//  ++a;
//  a++;
//
//  LinkedList<int> list_two = {1, 2, 3};
//  AssertEq(3, list_two.Length(), "empty list length should be zero");
//
//  //  Check AppendAll
//  //  list.Printf();
//  list_two.Printf();
//  list.AppendAll(list_two);
//  list.Printf();
//  list_two.Printf();
//
//  //   Check Prepend
//  AssertEq(6, list.Length(), "empty list length should be zero");
//  list.Prepend(62);
//  list.Printf();
//  //  AssertEq(2, list.Length(), "empty list length should be zero");
//  //  list.Printf();
//  //
//  // Check Insert
//  AssertEq(7, list.Length(), "empty list length should be zero");
//  list.InsertAt(1, 38);
//  AssertEq(8, list.Length(), "empty list length should be zero");
//  list.Printf();
//}
//

//  test_array_list();
//  test_linked_list();
//  test_with_unique_array_list();
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

/*Questions
 * Как сделать range based for
 * Почему написанно деструкторы
 *Конструктор копирования, оба объекта указывают на 1 массив или на 2 в
 *linkedlist Если придет не пустой массив в конструктор копирования Что лучше
 *сначала увеличивать index, а потом вставлять или наоборот? Chat Coding Garden
 * */
