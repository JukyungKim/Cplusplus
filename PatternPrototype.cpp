#include <iostream>

using namespace std;

class Shape{
public:
    virtual Shape* clone() = 0;
};

class Circle: public Shape{
public:
    int x, y, r;
    int temp;
    Circle(int x, int y, int r){
        this->x = x;
        this->y = y;
        this->r = r;
    }
    Shape* clone() override{
        return new Circle(*this);
    }
    void info(){
        cout << "Circle:" << x << " " << y << " " << r << endl;
    }
};

class Rectangle: public Shape{
public:
    int x, y;
    Rectangle(int x, int y){
        this->x = x;
        this->y = y;
    }
    Shape* clone() override{
        return new Rectangle(*this);
    }
    void info(){
        cout << "Rectangle" << x << " " << y << endl;
    }
};

int main()
{
    Circle *circle1 = new Circle(1, 2, 3);
    circle1->temp = 100;
    cout << circle1->temp << endl;

    circle1->info();

    Circle *circle2 = (Circle*)circle1->clone();
    circle2->info();

    Shape *shape = circle1->clone();
}

