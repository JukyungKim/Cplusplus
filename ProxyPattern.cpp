#include <iostream>

// Cash의 코드를 고치지 않고 알고리즘을 다르게 적용할 수 있다.
// CreditCard가 Cash에서 할 일을 대신 해준다.

using namespace std;

class Payment{
public:
    virtual void pay(int amount) = 0;
};

class Cash: public Payment{
public:
    void pay(int amount) override
    {
        cout << "Cash:" << amount << endl;
    }
};

class Gold: public Payment{
public:
    void pay(int amount) override
    {
        cout << "Gold:" << amount << endl;
    }
};

class CreditCard: public Payment{
public:
    CreditCard(Payment* payment)
    {
        this->payment = payment;
    }
    void pay(int amount) override
    {
        if(amount > 100){
            cout << "CreditCard:" << amount << endl;
        }
        else{
            payment->pay(amount);
        }
    }
private:
    Payment* payment;
};



class Store{
public:
    Store(Payment* payment)
    {
        this->payment = payment;
    }
    void buySomething(int amount)
    {
        payment->pay(amount);
    }
private:
    Payment* payment;
};

int main()
{
    Cash cash;
    Gold gold;
    CreditCard creditCard(&cash);

    Store store(&creditCard);
    store.buySomething(200);
    
    return 0;
}