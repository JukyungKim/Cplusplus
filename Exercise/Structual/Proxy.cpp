#include <iostream>
#include <memory>

using namespace std;

class IService{
public:
    virtual string provide(int num) = 0;
};

class Database{
public:
    string data1;
    string data2;
    Database(): data1("data 1"), data2("data 2"){}
};

class Service: public IService{
public:
    Service(shared_ptr<Database>& d): database(d){}
    virtual string provide(int num) override{
        cout << "access database" << endl;
        if(num == 1){
            return database->data1;
        }
        else if(num == 2){
            return database->data2;
        }
        return "";
    }
private:
    shared_ptr<Database> database;
};

class Proxy: public IService{
public:
    Proxy(Service* s): service(s), number(0){}
    virtual string provide(int num) override{
        if(number != num){
            data = service->provide(num);
        }
        number = num;
        return data;
    }
private:
    unique_ptr<Service> service;
    int number;
    string data;
};


int main()
{
    shared_ptr<Database> database = make_shared<Database>();
    unique_ptr<IService> service = make_unique<Proxy>(new Service(database));

    cout << service->provide(2) << endl;
    cout << service->provide(2) << endl;
    cout << service->provide(2) << endl;
    cout << service->provide(1) << endl;
    cout << service->provide(2) << endl;

    return 0;
}









// class IService{
// public:
//     virtual void provide(int num) = 0;
// };

// class Proxy: public IService{
// public:
//     string data;
//     int number;
//     Proxy(): number(0){}
//     virtual void provide(int num) override{
//         if(num != number){
//             getData(num);
//         }
//     }
//     void getData(int num){
//         if(num == 1){
//             data = "proxy data 1";
//         }
//         else if(num == 2){
//             data = "proxy data 2";
//         }
//     }
// };

// class Service: public IService{
// public:
//     Service(Proxy* p): proxy(p){}
//     virtual void provide(int num) override{
//         proxy->provide(num);
//         cout << proxy->data << endl;
//     }

// private:
//     unique_ptr<Proxy> proxy;
// };

// int main()
// {
//     unique_ptr<IService> service = make_unique<Service>(new Proxy());
//     service->provide(1);

//     return 0;
// }