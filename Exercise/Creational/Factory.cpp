#include <iostream>

using namespace std;

class BaseProduct{
public:
    string name;
    BaseProduct(string n): name(n){}
};

class IFactory{
public:
    virtual BaseProduct* create() = 0;
    virtual ~IFactory(){}
};

class ProductA: BaseProduct{
public:
    ProductA(string n): BaseProduct(n) {}
};

class ProductB: BaseProduct{
public:
    ProductB(string n): BaseProduct(n) {}
};

class FactoryA : public IFactory{
public:
    virtual BaseProduct* create() override{
        cout << "FactoryA creates ";
        return new BaseProduct("product a");
    }
    virtual ~FactoryA(){}
};

class FactoryB: public IFactory{
public:
    virtual BaseProduct* create() override{
        cout << "FactoryB creates ";
        return new BaseProduct("product b");
    }
    virtual ~FactoryB(){}
};

int main()
{
    IFactory* factory = new FactoryA();
    BaseProduct* product = factory->create();

    cout << product->name << endl;

    delete factory;

    factory = new FactoryB();
    product = factory->create();

    cout << product->name << endl;

    return 0;
}