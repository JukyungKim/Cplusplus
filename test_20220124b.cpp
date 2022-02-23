#include <iostream>

using namespace std;

class Base{
public:
    virtual void test(){
        cout << "base" << endl;
    }
};

class Sub: public Base{
public:
    virtual void test() override{
        Base::test();
        cout << "sub" << endl;

        Sub s;
        s.Base::test();
    }
};

int main()
{
    Sub* sub = new Sub();
    sub->test();

    return 0;
}