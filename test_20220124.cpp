#include <iostream>

using namespace std;

class Base{
public:
    Base(int a, int b){
        cout << "base initialize" << endl;
    }
};

class Child: public Base{
public:
};

int main()
{
    Child* child = new Child();

    return 0;
}