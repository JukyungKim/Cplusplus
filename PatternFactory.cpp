#include <iostream>
#include <memory>

using namespace std;

class Transport{
public:
    virtual void delivery() = 0;
};

class Truck: public Transport{
public:
    void delivery() override{
        cout << "Truck delivery" << endl;
    }
};

class Ship: public Transport{
public:
    void delivery() override{
        cout << "Ship delivery" << endl;
    }
};

class Factory{
public:
    Transport* create(){
        Transport *transport = make();
        cout << "Create in factory" << endl;

        return transport;
    }
    virtual Transport* make() = 0;
};

class TruckFactory: public Factory{
public:
    TruckFactory(){}
    Transport* make() override{
        cout << "Fatory is truck factory" << endl;
        return new Truck();
    }
};

class ShipFactory: public Factory{
public:
    ShipFactory(){}
    Transport* make() override{
        cout << "Factory is ship factory" << endl;
        return new Ship();
    }
};

Transport* makeTransport(std::shared_ptr<Factory> factory){
    return factory->create();
}

int main()
{
    Transport *ship = makeTransport(shared_ptr<Factory>(new ShipFactory()));
    Transport *truck = makeTransport(shared_ptr<Factory>(new TruckFactory()));

    return 0;
}

