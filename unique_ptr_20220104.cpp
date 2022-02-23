#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
    string str;    
    Test(const string s): str(s){}
    ~Test(){
        cout << "~Test " << str << endl;
    }
};

class Test2{
public:
    unique_ptr<Test> test;
    Test2(Test* test): test(test){}
    void show(){
        test = make_unique<Test>("bb");
        cout << test->str << endl;
    }
};

void foo(Test* t){
    unique_ptr<Test> tt(t);
}

int main()
{
    // 초기화
    Test2 t2(new Test("aaa"));
    t2.show();

    Test2 t22 = Test2(new Test("ccc"));

    // 소유권
    Test* tt = new Test("tt");

    unique_ptr<Test> tt1(tt);
    unique_ptr<Test> tt2(tt);

    cout << "1 ";
    cout << tt2->str << endl;

    cout << "------------" << endl;
    foo(tt);
    cout << "------------" << endl;
    cout << "2 ";
    // Undefined behavior : foo()에서 tt의 메모리가 제거되었음.
    cout << tt->str << endl;

    // unique_ptr 두 개 생성 후 하나만 지웠을 때 발생하는 현상
    Test* a1 = new Test("a1");
    unique_ptr<Test> a2(a1);
    unique_ptr<Test> a3(a1);
    cout << "3 ";
    cout << a1->str << endl;
    cout << "------------" << endl;
    a2.reset();
    cout << a3->str << endl;    // undefined behavior : a2.reset()으로 메모리 해제.
    cout << "------------" << endl;
    // cout << a2->str << endl; // error
    cout << "------------" << endl;
    delete a1;
    cout << "------------" << endl;
    a1 = nullptr;
    cout << "4 ";
    // cout << a1->str << endl; // error
    cout << a3->str << endl;    // 이상 없음

    Test* aa1 = new Test("a2");
    delete aa1;
    cout << aa1->str << endl;   // undefined behavior




    return 0;
}