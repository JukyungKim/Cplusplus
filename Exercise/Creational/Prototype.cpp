#include <iostream>
#include <memory>

using namespace std;

class IPrototype{
public:
    virtual unique_ptr<IPrototype> clone() = 0;
    virtual void describe() = 0;
    virtual void setValue(int s, int w) = 0;
};

class PrototypeA: public IPrototype{
public:
    int size;
    int weight;
    PrototypeA(int s, int w): size(s), weight(w) {}
    PrototypeA(PrototypeA* prototype){
        size = prototype->size;
        weight = prototype->weight;
    }

    virtual unique_ptr<IPrototype> clone() override{
        return make_unique<PrototypeA>(new PrototypeA(this));
    }

    virtual void describe() override{
        cout << size << " " << weight << endl;
    }

    virtual void setValue(int s, int w){
        size = s;
        weight = w;
    }
};

int main()
{
    unique_ptr<IPrototype> prototype(new PrototypeA(1 ,2 ));
    prototype->describe();

    unique_ptr<IPrototype> p1 = prototype->clone();
    p1->describe();

    prototype->setValue(10, 20);

    prototype->describe();
    p1->describe();

    prototype = NULL;

    return 0;
}