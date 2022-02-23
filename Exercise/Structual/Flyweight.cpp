#include <iostream>
#include <memory>

using namespace std;

class Particle{
public:
    Particle(string n): name(n){}
    void operate(){
        cout << name << endl;
    }
private:
    string name;
};

class Marine{
public:
    Marine(shared_ptr<Particle> p): particle(p){}
    void attack(){
        particle->operate();
    }
private:
    shared_ptr<Particle> particle;
};

int main()
{
    shared_ptr<Particle> particle = make_shared<Particle>("gun");
    unique_ptr<Marine> marine1 = make_unique<Marine>(particle);
    unique_ptr<Marine> marine2 = make_unique<Marine>(particle);

    marine1->attack();
    marine2->attack();
    
    return 0;
}