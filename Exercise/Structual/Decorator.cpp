#include <iostream>
#include <memory>

using namespace std;

class AComponent{
public:
    AComponent(string n): name(n){}
    virtual void operate(){
        if(decorator == nullptr){
            cout << "decorator null" << endl;
        }
        else{
            decorator->operate();
        }
    }
    void decorate(AComponent* deco){
        if(decorator == nullptr){
            decorator = unique_ptr<AComponent>(deco);
        }
        else{
            decorator->decorate(deco);
        }
    }
protected:
    unique_ptr<AComponent> decorator;
    string name;
};

class Thing: public AComponent{
public:
    Thing(string n): AComponent(n){}
    virtual void operate() {
        AComponent::operate();
        cout << "thing" << endl;
    }
};

class DecoratorA: public AComponent{
public:
    DecoratorA(string n): AComponent(n){}
    virtual void operate() {
        AComponent::operate();
        cout << name << " ";
    }
};

int main()
{
    unique_ptr<AComponent> component = make_unique<Thing>("thing");

    component->decorate(new DecoratorA("deco1"));
    component->decorate(new DecoratorA("deco2"));

    component->operate();

    return 0;
}






//////////////////////////////////////////

// class IComponent{
// public:
//     virtual void operate() = 0;
// };

// class Thing: public IComponent{
// public:
//     virtual void operate() override{
//         cout << "thing" << endl;
//     }
// };

// class ADecorator: public IComponent{
// public:
//     ADecorator(IComponent* com, string name): component(com), name(name){}
//     // virtual void operate() override = 0;
// protected:
//     unique_ptr<IComponent> component;
//     string name;
// };


// class DecoratorA: public ADecorator{
// public:
//     DecoratorA(IComponent* com, string name): ADecorator(com, name){}
//     virtual void operate() override{
//         component->operate();
//         cout << name << " " ;
//     }
// };

// int main()
// {
//     cout << "start" << endl;

//     unique_ptr<IComponent> component = make_unique<Thing>();
//     unique_ptr<IComponent> deco1 = make_unique<DecoratorA>(component.get(), "deco1");
//     unique_ptr<IComponent> deco2 = make_unique<DecoratorA>(deco1.get(), "deco2");

//     // IComponent* component = new Thing();
//     // IComponent* deco1 = new DecoratorA(component, "deco1");
//     // IComponent* deco2 = new DecoratorA(deco1, "deco2");


//     deco2->operate();

//     return 0;
// }