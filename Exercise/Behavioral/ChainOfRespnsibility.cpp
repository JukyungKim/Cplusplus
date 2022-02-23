#include <iostream>
#include <memory>

using namespace std;

class IRequest{
public:
    bool complete;
    IRequest(): complete(false){}
    void setNext(shared_ptr<IRequest> q){
        request = q;
    }
    virtual void check(){
        if(request != nullptr){
            request->check();
        }
    }
protected:
    shared_ptr<IRequest> request;
};

class Condition1: public IRequest{
public:
    virtual void check(){
        if(complete){
            cout << "condition 1 complete" << endl;
        }
        else{
            IRequest::check();
        }
    }
};

class Condition2 : public IRequest{
public:
    virtual void check(){
        if(complete){
            cout << "condition 2 complete" << endl;
        }
        else{
            IRequest::check();
        }
    }
};

int main()
{
    shared_ptr<IRequest> request1 = make_shared<Condition1>();
    shared_ptr<IRequest> request2 = make_shared<Condition2>();

    request1->complete = true;
    request1->check();
    cout << "----" << endl;
    request1->setNext(request2);
    request1->complete = false;

    request1->check();
    cout << "----" << endl;
    request1->complete = false;
    request2->complete = true;

    request1->check();
    cout << "----" << endl;
    return 0;
}


