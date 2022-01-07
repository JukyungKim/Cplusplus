#include <iostream>
#include <memory>

using namespace std;

// object adapter

class Service{
public:
    void operate(){
        cout << "service operate" << endl;
    }
};

class IAdapter{
public:
    virtual void method() = 0;      
};

class Adapter: public IAdapter{
public:
    unique_ptr<Service> adaptee;

    Adapter(Service* a): adaptee(a){

    }
    virtual void method() override{
        adaptee->operate();
    }
};

class Client{
public:
    void logic(const unique_ptr<IAdapter>& adapter){
        adapter->method();
    }
};

int main()
{
    unique_ptr<Client> client = make_unique<Client>();
    unique_ptr<IAdapter> adapter = make_unique<Adapter>(new Service());
    // unique_ptr<IAdapter> adapter(new Adapter(new Service()));

    client->logic(adapter);

    return 0;
}