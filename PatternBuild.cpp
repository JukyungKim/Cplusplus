#include <iostream>
#include <vector>

using namespace std;

class Car{
public:
    void setWindow(int n) { windowNum = n;}
    void setSeat(int n) { seatNum = n;}
    void info() { cout << "car : window " << windowNum << " seat " << seatNum << endl;}
private:
    int windowNum;
    int seatNum;
};

class CarManual{
public:
    void howToUseWindow(string str){ window = str;}
    void howToUseSeat(string str){ seat = str;}
    void info(){
        cout << window << endl;
        cout << seat << endl;
    }
private:
    string window;
    string seat;
};

class Builder{
public:
    virtual void setSeat() = 0;
    virtual void setWindow() = 0;
};

class CarSedanBuilder: public Builder{
public:
    CarSedanBuilder() { car = new Car();}
    void setSeat() override{
        cout << "make sedan seat" << endl;
        car->setSeat(4);
    }
    void setWindow() override{
        cout << "make sedan window" << endl;
        car->setWindow(4);
    }
    Car* get() { return car;}
private:
    Car *car;
};

class CarSuvBuilder: public Builder{
public:
    CarSuvBuilder() { car = new Car();}
    void setSeat() override{
        cout << "make suv seat" << endl;
        car->setSeat(7);
    }
    void setWindow() override{
        cout << "make suv window" << endl;
        car->setWindow(7);
    }
    Car* get() { return car;}
private:
    Car *car;
};

class CarManualBuilder: public Builder{
public:
    CarManualBuilder() { carManual = new CarManual();}
    void setSeat() override{
        cout << "make car manual seat" << endl;
        carManual->howToUseSeat("make seat well");
    }
    void setWindow() override{
        carManual->howToUseWindow("make window well");
    }
    CarManual* get() { return carManual;}
private:
    CarManual *carManual;
};

class Director{
public:
    void buildSeatAndWindow(){
        cout << "build seat and window" << endl;
        builder->setSeat();
        builder->setWindow();
    }
    void buildOnlySeat(){
        cout << "build only seat" << endl;
        builder->setSeat();
    }
    void setBuilder(Builder *builder){
        this->builder = builder;
    }
private:
    Builder *builder;
};

int main()
{   
    CarSedanBuilder *builderSedan = new CarSedanBuilder();
    Director *director = new Director();
    director->setBuilder(builderSedan);
    director->buildSeatAndWindow();
    Car *car = builderSedan->get();
    car->info();

    CarManualBuilder *builderManual = new CarManualBuilder();
    director->setBuilder(builderManual);
    director->buildSeatAndWindow();
    CarManual *carManual = builderManual->get();
    carManual->info();

    return 0;
}