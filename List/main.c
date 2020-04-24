#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void AssertEq(int expected, int actual, const char *msg) {
  if (expected != actual) {
    printf("Test failed: %s\n expected %d but got %d\n", msg, expected, actual);
    exit(-1);
  }
}

int main() {
  List *list = NewList();
  List *list_two = NewList();

  Append(list, 1);
  AssertEq(1, Length(list), "empty list length should be zero");

  Append(list, 2);
  AssertEq(2, Length(list), "empty list length should be zero");
  //  Printf(list);

  Prepend(list, 0);
  AssertEq(3, Length(list), "empty list length should be zero");
  //  Printf(list);

  Prepend(list_two, 2);
  Append(list_two, 3);
  Append(list_two, 4);
  Append(list_two, 4);
  Printf(list);
  Printf(list_two);
  AppendAll(list, list_two);
  Printf(list);
  DestroyList(list_two);
  Printf(list);
  Printf(list_two);
  // AssertEq(3, GetAt(list, 3), "empty list length should be zero");
  //
  //  InsertAt(list, 1, -1);
  //  Printf(list);
  //
  //  RemoveAt(list, 2);
  //  Printf(list);

  // Printf(list_two);
  // RemoveAll(list_two);
  // AssertEq(0, Length(list_two), "empty list length should be zero");
  // Printf(list_two);
  //
  //  Pop(list);
  //  AssertEq(5, Length(list), "empty list length should be zero");
  //  Printf(list);
  //
  //  AssertEq(0, Length(list_two), "empty list length should be zero");
  //  Printf(list_two);
  //
  //  Printf(list);
  //  Dequeue(list);
  //  Printf(list);
  //  AssertEq(1, Length(list), "Length([42]) should be 1");
  //  AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
  //
  //  Prepend(list, 9);
  //  AssertEq(9, GetAt(list, 0), "GetAt([9, 42], 0) should be 9");
  //  AssertEq(42, GetAt(list, 1), "GetAt([9, 42], 0) should be 9");
  //
  //  Append(list, 10);
  //  Append(list, 11);
  //  Append(list, 13);
  //  Append(list, 14);
  //  Append(list, 15);
  //  Append(list, 16);
  //  Printf(list);
  //
  //  Dequeue(list);
  //  Dequeue(list);
  //  Dequeue(list);
  //  Dequeue(list);
  //  Dequeue(list);
  //  Printf(list);
  //
  //  Pop(list);
  //  Printf(list);
  //  Append(list_two, 2);
  //  AssertEq(1, Length(list_two), "Length([42]) should be 1");
  //  AssertEq(2, GetAt(list_two, 0), "GetAt([42], 0) should be 42");
  //
  //  Append(list_two, 3);
  //  AssertEq(2, Length(list_two), "Length([42]) should be 1");
  //  AssertEq(2, GetAt(list_two, 0), "GetAt([42], 0) should be 42");
  //  AssertEq(3, GetAt(list_two, 1), "GetAt([42], 0) should be 42");
  //
  //  Prepend(list_two, 1);
  //  AssertEq(3, Length(list_two), "Length([42]) should be 1");
  //  AssertEq(1, GetAt(list_two, 0), "GetAt([42], 0) should be 42");
  //
  //  AppendAll(list, list_two);
  //  Printf(list);
  //
  //  InsertAt(list, 2, 0);
  //  AssertEq(0, GetAt(list, 3), "GetAt([42], 0) should be 42");
  //  Printf(list);
  //
  //  InsertAt(list, 0, 62);
  //  AssertEq(62, GetAt(list, 1), "GetAt([42], 0) should be 42");
  //  Printf(list);
  //
  //  RemoveAt(list, 3);
  //  Printf(list);
  //
  //  Pop(list);
  //  Printf(list);
  //
  //  AssertEq(50, Length(list), "Length([9, 62, 42]) should be 3");
  //  AssertEq(50, GetAt(list, 1), "GetAt([9, 62, 42], 1) should be 62");
  //
  //  RemoveAt(list, 2);

  DestroyList(list);

  // TODO: Здесь куча разных ваших тестов!!!
}