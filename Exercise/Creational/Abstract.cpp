#include <iostream>

using namespace std;

class IProductChair{
public:
    virtual void sit() = 0;
    virtual ~IProductChair(){}
};

class IProductDesk{
public:
    virtual void put() = 0;
    virtual ~IProductDesk(){}
};

class ChairA: public IProductChair{
public:
    virtual void sit() override{
        cout << "sit a" << endl;
    }
    virtual ~ChairA(){}
};

class ChairB: public IProductChair{
public:
    virtual void sit() override{
        cout << "sit b" << endl;
    }
    virtual ~ChairB(){}
};

class DeskA: public IProductDesk{
public:
    virtual void put() override{
        cout << "put a" << endl;
    }
    virtual ~DeskA(){}
};

class DeskB: public IProductDesk{
public:
    virtual void put() override{
        cout << "put b" << endl;
    }
    virtual ~DeskB(){}
};

class AbstractFactory{
public:
    virtual IProductChair* createChair() = 0;
    virtual IProductDesk* createDesk() = 0;
    virtual ~AbstractFactory(){}
};

class FactoryModern: public AbstractFactory{
public:
    virtual IProductChair* createChair(){
        return new ChairA();
    }
    virtual IProductDesk* createDesk(){
        return new DeskA();
    }
    virtual ~FactoryModern(){}
};

class FactoryGothic: public AbstractFactory{
public:
    virtual IProductChair* createChair(){
        return new ChairB();
    }
    virtual IProductDesk* createDesk(){
        return new DeskB();
    }
    virtual ~FactoryGothic(){}
};


int main()
{
    AbstractFactory* factory = new FactoryModern();

    IProductChair* chair = factory->createChair();
    IProductDesk* desk = factory->createDesk(); 

    chair->sit();
    desk->put();

    delete factory;
    delete chair;
    delete desk;

    factory = new FactoryGothic();
    chair = factory->createChair();
    desk = factory->createDesk();

    chair->sit();
    desk->put();
    

    return 0;
}