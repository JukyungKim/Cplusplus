#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Product{
public:
    void setPart(const string& str){
        parts.push_back(str);
    }
    void describe(){
        for(auto part: parts){
            cout << part << endl;
        }
        cout << size << " " << weight << " " << isSwim << endl;
    }
private:
    vector<string> parts;
    int size;
    int weight;
    bool isSwim;
};

class IBuilder{
public:
    virtual void makePart1() = 0;
    virtual void makePart2() = 0;
    virtual void makePart3() = 0;
    virtual unique_ptr<Product> getProduct() = 0;
    virtual void reset() = 0;
};

class Builder: public IBuilder{
public:
    virtual void makePart1() override{
        product->setPart("part1");
    }
    virtual void makePart2() override{
        product->setPart("part2");
    }
    virtual void makePart3() override{
        product->setPart("part3");
    }
    virtual unique_ptr<Product> getProduct() override{
        return move(product);
    }
    virtual void reset(){
        product = make_unique<Product>();
    }
private:
    unique_ptr<Product> product;
};

class Director{
public:
    unique_ptr<IBuilder> builder;
    Director(IBuilder* builder): builder(builder){}
    void buildA(){
        builder->reset();
        builder->makePart1();
    }
    void buildB(){
        builder->reset();
        builder->makePart1();
        builder->makePart2();
    }
    void buildC(){
        builder->reset();
        builder->makePart1();
        builder->makePart2();
        builder->makePart3();
    }
};

int main()
{
    unique_ptr<Director> director(new Director(new Builder()));
    director->buildA();
    unique_ptr<Product> product = director->builder->getProduct();
    product->describe();

    director->buildC();
    product = director->builder->getProduct();
    product->describe();

    return 0;
}