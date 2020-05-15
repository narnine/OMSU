#include "../include/array_list.h"
#include "../include/linked_list.h"
#include "vector"
#include <bits/unique_ptr.h>
#include <gtest/gtest.h>

using namespace std;

TEST(ArrayList, arraylist_just_create_arr_Test) {
  arraylist::ArrayList<std::unique_ptr<int>> arrayList;
}

TEST(LinkedList, linkedlist_just_create_arr_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList_one = {
      std::make_unique<int>(42)};
  linkedlist::LinkedList<int> linkedList_two;
}

TEST(LinkedList, linkedlist_append_and_prepend_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList;
  linkedList.Append(std::make_unique<int>(42));
  ASSERT_EQ(*(linkedList[0]), 42);
  ASSERT_EQ(linkedList.Length(), 1);
  linkedList.Append(std::make_unique<int>(62));
  ASSERT_EQ(*(linkedList[1]), 62);
  ASSERT_EQ(linkedList.Length(), 2);
  linkedList.Prepend(std::make_unique<int>(24));
  ASSERT_EQ(*(linkedList[0]), 24);
  ASSERT_EQ(*(linkedList[1]), 42);
  ASSERT_EQ(*(linkedList[2]), 62);
  ASSERT_EQ(linkedList.Length(), 3);
}

TEST(LinkedList, linkedlist_insert_at_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList;
  linkedList.InsertAt(0, std::make_unique<int>(1));
  ASSERT_EQ(*(linkedList[0]), 1);
}

TEST(LinkedList, linkedlist_pop_and_deque_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList;
  linkedList.Append(std::make_unique<int>(1));
  linkedList.Append(std::make_unique<int>(2));
  linkedList.Append(std::make_unique<int>(4));
  linkedList.Append(std::make_unique<int>(3));
  ASSERT_EQ(linkedList.Length(), 4);
  ASSERT_EQ(*(linkedList.Pop()), 3);
  ASSERT_EQ(*(linkedList.Dequeue()), 1);
  ASSERT_EQ(linkedList.Length(), 2);
}

TEST(LinkedList, linkedlist_remove_at_and_remove_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList;
  linkedList.Append(std::make_unique<int>(1));
  linkedList.Append(std::make_unique<int>(2));
  linkedList.Append(std::make_unique<int>(4));
  linkedList.Append(std::make_unique<int>(3));
  linkedList.RemoveAt(2);
  ASSERT_EQ(linkedList.Length(), 3);
  ASSERT_EQ(*(linkedList[0]), 1);
  ASSERT_EQ(*(linkedList[1]), 2);
  ASSERT_EQ(*(linkedList[2]), 3);
  linkedList.RemoveAll();
  ASSERT_EQ(linkedList.Length(), 0);
}

TEST(LinkedList, linkedlist_remove_all_Test) {
  linkedlist::LinkedList<std::unique_ptr<int>> linkedList_one;
  linkedList_one.Append(std::make_unique<int>(1));
  linkedList_one.Append(std::make_unique<int>(2));
  linkedList_one.Append(std::make_unique<int>(3));
  linkedList_one.Append(std::make_unique<int>(4));

  linkedlist::LinkedList<std::unique_ptr<int>> linkedList_two;
  linkedList_one.Append(std::make_unique<int>(5));
  linkedList_one.Append(std::make_unique<int>(6));
  linkedList_one.Append(std::make_unique<int>(7));
  linkedList_one.Append(std::make_unique<int>(8));

  linkedList_one.AppendAll(linkedList_two);
  ASSERT_EQ(linkedList_one.Length(), 8);
  ASSERT_EQ(*(linkedList_one[0]), 1);
  ASSERT_EQ(*(linkedList_one[1]), 2);
  ASSERT_EQ(*(linkedList_one[2]), 3);
  ASSERT_EQ(*(linkedList_one[3]), 4);
  ASSERT_EQ(*(linkedList_one[4]), 5);
  ASSERT_EQ(*(linkedList_one[5]), 6);
  ASSERT_EQ(*(linkedList_one[6]), 7);
  ASSERT_EQ(*(linkedList_one[7]), 8);

  //  ASSERT_EQ(*(linkedList_one[4]), 5);
  //  ASSERT_EQ(*(linkedList_one[5]), 6);
  //  ASSERT_EQ(*(linkedList_one[6]), 7);
  //  ASSERT_EQ(*(linkedList_one[7]), 8);
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
 * Про std::move в POP можно ли было по-другому
 * AppedAll and Printf
 * Как сделать range based for
 * Почему написанно деструкторы
 *Что лучше сначала увеличивать index, а потом вставлять или наоборот?
 * */
