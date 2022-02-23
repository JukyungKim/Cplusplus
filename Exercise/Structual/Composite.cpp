#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class AComposite{
public:
    string name;
    AComposite(const string& n): name(n){}
    virtual void add(AComposite* comp) {}
    virtual void operate() = 0;
};

class Branch: public AComposite{
public:
    vector<unique_ptr<AComposite>> composites;
    vector<int> tt;
    Branch(const string& s): AComposite(s){}
    virtual void add(AComposite* comp) override{
        unique_ptr<AComposite> c(comp);
        composites.push_back(move(c));
    }  
    virtual void operate() override{
        cout << "branch" << " " << name << endl;
        for(auto& e: composites){
            e->operate();
        }
    }
};

class Leap: public AComposite{
public:
    Leap(const string& s): AComposite(s){}
    virtual void operate(){
        cout << "Leap" << " " << name << endl;
    }
};

int main()
{
    unique_ptr<AComposite> composite = make_unique<Branch>("1");
    composite->add(new Leap("a"));
    composite->add(new Leap("b"));

    composite->operate();

    unique_ptr<AComposite> composite2 = make_unique<Branch>("2");

    composite2->add(new Leap("c"));
    composite2->add(new Leap("d"));

    composite->add(composite2.get());    
    composite->add(composite2.get());

    composite->operate();

    return 0;
}




////////////////////////////////////////////////////////////////////////
// 방법2

// class IComposite{
// public:
//     vector<IComposite*> composites;
//     virtual void operate(){
//         for(auto e: composites){
//             e->operate();
//         }
//     }
//     void add(IComposite* composite){
//         composites.push_back(composite);
//     }
// };

// class Node: public IComposite{
// public:

// };

// class LeapA: public IComposite{
// public:
//     string str;
//     LeapA(const string s): str(s) {}
//     virtual void operate() override{
//         cout << str << endl;
//     }
// };

// int main()
// {
//     IComposite* composite = new IComposite();
//     IComposite* node1 = new Node();
//     node1->add(new LeapA("aa"));
//     node1->add(new LeapA("bb"));
//     composite->add(node1);

//     composite->operate();

//     cout << endl;

//     IComposite* node2 = new Node();
//     node2->add(new LeapA("cc"));
//     composite->add(node2);

//     composite->operate();


//     return 0;
// }

