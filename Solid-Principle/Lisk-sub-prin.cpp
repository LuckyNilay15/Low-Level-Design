#include <iostream>
using namespace std;

class Bird{
    public:
    virtual void eat(){
        cout<<"Bird is eating";
    }
};

class FlyingBird: public Bird{
    public:
    virtual void fly()=0;
};

class WalkingBird: public Bird{
    public:
    virtual void walk()=0;

};

class Sparrow: public FlyingBird{
    void fly(){
        cout<<"Sparrow is flying";
    }
};

class Ostrich: public WalkingBird{
    void walk(){
        cout<<"Ostrich is walking";
    }
};

// This function takes ANY Bird safely without worrying if they'll crash on fly() 
void feedBird(Bird& bird){
     bird.eat();
}

int main(){
    Sparrow s;
    Ostrich o;
    s.fly();
    o.walk();
    return 0;
}