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

class IFactoryChair{
public:
    virtual IProductChair* create() = 0;
    virtual ~IFactoryChair(){}
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

class IFactoryDesk{
public:
    virtual IProductDesk* create() = 0;
    virtual ~IFactoryDesk(){}
};

class FactoryChairA: public IFactoryChair{
public:
    virtual IProductChair* create() override{
        return new ChairA();
    }
    virtual ~FactoryChairA(){}
};

class FactoryChairB: public IFactoryChair{
public:
    virtual IProductChair* create() override{
        return new ChairB();
    }
    virtual ~FactoryChairB(){}
};

class FactoryDeskA: public IFactoryDesk{
public:
    virtual IProductDesk* create() override{
        return new DeskA();
    }
    virtual ~FactoryDeskA(){}
};

class FactoryDeskB: public IFactoryDesk{
public:
    virtual IProductDesk* create() override{
        return new DeskB();
    }
    virtual ~FactoryDeskB() {}
};

class AbstractFactory{
public:
    virtual IProductChair* createChair(IFactoryChair* factoryChair) = 0;
    virtual IProductDesk* createDesk(IFactoryDesk* factoryDesk) = 0;
    virtual ~AbstractFactory(){}
};

class FactoryModern: public AbstractFactory{
public:
    virtual IProductChair* createChair(IFactoryChair* factoryChair){
        return factoryChair->create();
    }
    virtual IProductDesk* createDesk(IFactoryDesk* factoryDesk){
        return factoryDesk->create();
    }
    virtual ~FactoryModern(){}
};

class FactoryGothic: public AbstractFactory{
public:
    virtual IProductChair* createChair(IFactoryChair* factoryChair){
        return factoryChair->create();
    }
    virtual IProductDesk* createDesk(IFactoryDesk* factoryDesk){
        return factoryDesk->create();
    }
    virtual ~FactoryGothic(){}
};


int main()
{
    AbstractFactory* abstractFactory = new FactoryModern();
    IFactoryChair* factoryChair = new FactoryChairA();
    IFactoryDesk* factoryDesk = new FactoryDeskA();
    IProductChair* chair = abstractFactory->createChair(factoryChair);
    IProductDesk* desk = abstractFactory->createDesk(factoryDesk);

    chair->sit();
    desk->put();

    delete abstractFactory;
    delete factoryChair;
    delete factoryDesk;
    delete chair;
    delete desk;
    
    abstractFactory = new FactoryGothic();
    factoryChair = new FactoryChairB();
    factoryDesk = new FactoryDeskB();
    chair = abstractFactory->createChair(factoryChair);
    desk = abstractFactory->createDesk(factoryDesk);

    chair->sit();
    desk->put();
    

    return 0;
}