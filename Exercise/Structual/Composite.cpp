#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class AComposite{
public:
    string name;
    AComposite(string n): name(n){}
    virtual void add(AComposite* comp) = 0;
    virtual void operate() = 0;
};

class Branch: public AComposite{
public:
    vector<unique_ptr<AComposite>> composites;
    Branch(string s): AComposite(s){}
    virtual void add(AComposite* comp) override{
        unique_ptr<Branch> c = new Branch("ss");
        composites.push_back(move(c));
    }  
    virtual void operate() override{
        for(auto e: composites){
            e->operate();
        }
    }
};

class Leap: public AComposite{
public:
    Node(string s): AComposite(s){}
    
};








class IComposite{
public:
    vector<IComposite*> composites;
    virtual void operate(){
        for(auto e: composites){
            e->operate();
        }
    }
    void add(IComposite* composite){
        composites.push_back(composite);
    }
};

class Node: public IComposite{
public:

};

class LeapA: public IComposite{
public:
    string str;
    LeapA(const string s): str(s) {}
    virtual void operate() override{
        cout << str << endl;
    }
};

int main()
{
    IComposite* composite = new IComposite();
    IComposite* node1 = new Node();
    node1->add(new LeapA("aa"));
    node1->add(new LeapA("bb"));
    composite->add(node1);

    composite->operate();

    cout << endl;

    IComposite* node2 = new Node();
    node2->add(new LeapA("cc"));
    composite->add(node2);

    composite->operate();


    return 0;
}

