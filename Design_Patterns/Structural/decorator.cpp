#include <iostream>
#include <string>
using namespace std;

class ICoffee{
    public:
    virtual string getDescription()=0;
    virtual double getCost()=0;
};

class BasicCoffee:public ICoffee{
    public:
    string getDescription(){
        return "Basic Coffee";
    }
    double getCost(){
        return 2.00;
    }
};

class CoffeeDecorator:public ICoffee{
    private:
    ICoffee* wrappedCoffee;
    public:
    CoffeeDecorator(ICoffee* coffeeToWrap){
        wrappedCoffee=coffeeToWrap;
    }
    string getDescription(){
        return wrappedCoffee->getDescription();
    }
    double getCost(){
        return wrappedCoffee->getCost();
    }
}; 

class MilkDecorator:public CoffeeDecorator{
    public:
    MilkDecorator(ICoffee* coffeeToWrap):CoffeeDecorator(coffeeToWrap){}
    string getDescription(){
        return CoffeeDecorator::getDescription()+", Milk";
    }
    double getCost(){
        return CoffeeDecorator::getCost()+0.50;
    }
}; 

class SugarDecorator:public CoffeeDecorator{
    public:
    SugarDecorator(ICoffee* coffeeToWrap):CoffeeDecorator(coffeeToWrap){}
    string getDescription(){
        return CoffeeDecorator::getDescription()+", Sugar";
    }
    double getCost(){
        return CoffeeDecorator::getCost()+0.25;
    }
}; 

class ExtraShotDecorator:public CoffeeDecorator{
    public:
    ExtraShotDecorator(ICoffee* coffeeToWrap):CoffeeDecorator(coffeeToWrap){}
    string getDescription(){
        return CoffeeDecorator::getDescription()+", Extra Shot";
    }
    double getCost(){
        return CoffeeDecorator::getCost()+1.00;
    }
}; 

int main(){
    cout<<"--Customer 1: Just black coffee";
    ICoffee* myCoffee=new BasicCoffee();
    cout<<"Order"<<myCoffee->getDescription()<<endl;
    cout<<"Cost"<<myCoffee->getCost()<<endl;

    cout<<"--Customer 2:Wants Milk and Sugar!";
    ICoffee* fancyCoffee=new BasicCoffee();
    fancyCoffee=new MilkDecorator(fancyCoffee);
    fancyCoffee=new SugarDecorator(fancyCoffee);
    cout<<"Order"<<fancyCoffee->getDescription()<<endl;
    cout<<"Cost"<<fancyCoffee->getCost()<<endl;

    cout<<"--Customer 3: Wants Milk, Sugar and Extra Shot!";
    ICoffee* superFancyCoffee=new BasicCoffee();
    superFancyCoffee=new MilkDecorator(superFancyCoffee);
    superFancyCoffee=new SugarDecorator(superFancyCoffee);
    superFancyCoffee=new ExtraShotDecorator(superFancyCoffee);
    cout<<"Order"<<superFancyCoffee->getDescription()<<endl;
    cout<<"Cost"<<superFancyCoffee->getCost()<<endl;
    return 0;
}