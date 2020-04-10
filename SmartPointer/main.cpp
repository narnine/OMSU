#include <iostream>
#include "include/scoped_ptr.h"
using namespace std;
void assert(int a, int b){
    if (a != b){
        cout <<"ERROR"<< endl;
        exit(-1);
    }else{
        cout << "FUN" << endl;
    }
}

void test_0(){
    ScopedPtr<int> scopedptr(new int(5));
    int* a = scopedptr.Get();
    assert(*a, 5);
    *scopedptr = 33;
    assert(*scopedptr, 33);
};

int main() {
    test_0();
  return 0;
}
/*Questions:
 *  T& operator*() const { *ptr_; } зачем тут ссылка
 *
 *
 * */