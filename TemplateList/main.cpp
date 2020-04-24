#include "include/array_list.h"
#include "include/linked_list.h"

using namespace std;

// class ArrayList;
// template <typename T>
// void Print(ArrayList<T> &list) {
//  for (int i = 0; i < list.GetSize(); i++) {
//    cout << list.array_[i] << " ";
//  }
//}

int main() {
  ArrayList<int> list = {1, 2};
  list.Print();
  list.Append(3);

  for (auto &element : list) {
    cout << element << " ";
  }

  for (auto el = list.begin(); el != list.end(); el++) {
    cout << el << " ";
  }
  ArrayList<int> list_two = {1, 2, 3, 4};

  return 0;
}
/*Questions
 *про конструктор: как он должен выглядеть, иногда мы пишем через :
 *Конструктор копирования, оба объекта указывают на 1 массив или на 2
 * Если придет не пустой массив в конструктор копирования
 * Что лучше сначала увеличивать index, а потом вставлять или наоборот?
 * Chat
 * Coding Garden
 * */
