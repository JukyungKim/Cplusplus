#include <iostream>

using namespace std;

class Chair{
public:
    virtual void sit() = 0;
};

class Chair1: public Chair{
public:
    void sit() override{
        cout << "Compotable chair" << endl;
    };
};

class Chair2: public Chair{
public:
    void sit() override{
        cout << "Chair with caster" << endl;
    }
};

class Table{
public:
    virtual void eat() = 0;
};

class Table1: public Table{
public:
    void eat() override{
        cout << "Table1" << endl;
    }
};

class Table2: public Table{
public:
    void eat() override{
        cout << "Table2" << endl;
    }
};

class Factory{
public:
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
};

class ModernFactory: public Factory{
public:
    Chair* createChair() override{
        cout << "create chair1" << endl;
        cout << "not called by constructor" << endl;
        return new Chair1();
    }
    Table* createTable() override{
        cout << "create table1" << endl;
        cout << "not called by constructor" <<endl;

        return new Table1();
    }
};

class GothicFactory: public Factory{
public:
    Chair* createChair() override{
        cout << "create chair2" << endl;
        return new Chair2();
    }
    Table* createTable() override{
        cout << "create table2" << endl;
        return new Table2();
    }
};

int main()
{
    Factory *modern = new ModernFactory();
    Chair *chair = modern->createChair();
    chair->sit();
    Table *table = modern->createTable();
    table->eat();

    return 0;
}