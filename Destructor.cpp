#include <iostream>

using namespace std;

class DestructorTest{
public:
    DestructorTest(){
        cout << "Constructor" << endl;
    }
    ~DestructorTest(){
        cout << "Destructor" << endl;
    }
};

int main()
{
    DestructorTest *des = new DestructorTest();
    delete des;

    return 0;
}