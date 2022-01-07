#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
    string str;    
    Test(const string s): str(s){}
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


int main()
{
    Test2 t2(new Test("aaa"));
    t2.show();

    Test2 t22 = Test2(new Test("ccc"));

    return 0;
}