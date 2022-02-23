#include <iostream>
#include <memory>

using namespace std;

void foo(unique_ptr<int> uptr){
    *uptr = 100;
}

class Test{

};

void foo2(unique_ptr<Test> t){

}

void foo3(int n){

}

int main(){
    int* ptr = new int;
    // foo(new int());
    // foo2(new Test());
    // foo3('c');
    unique_ptr<int> uptr(new int);

    return 0;
}