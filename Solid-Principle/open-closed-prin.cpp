#include<iostream>
#include<vector>
#using namespace std;
class Shape{
    public:
    virtual double area()=0;
    virtual ~Shape()=default;
};

class Rectangle: public Shape {
    double w,h;
    public:
    Rectangle(double w, double h)  {
        this.w=w;
        this.h=h;
    }
    double area(){
        return w*h;
    }
};


class Circle: public Shape{
    double r;
    public:
    Circle(double r): {
        this.r=r;
    }
    double area() {return 3.14159*r*r}
};


class AreaCalculator{
    public:
    double calaculateTotal(vector<Shape*>&shapes){
        double total=0;
        for(auto shape:shapes){
            total+=shape->area();
        }
        return total;
    }
};

int main(){
    Rectangle r1(10,20);
    Circle c1(10);
    vector<Shape*>shapes;
    shapes.push_back(&r1);
    shapes.push_back(&c1);
    AreaCalculator calc;
    cout<<calc.calaculateTotal(shapes);
    return 0;
}