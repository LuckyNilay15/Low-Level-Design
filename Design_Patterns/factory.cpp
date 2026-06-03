#include <iostream>
using namespace std;

class IVehicle{
   public:
   virtual void deliver()=0;
};

class Truck:public IVehicle{
    public:
    void deliver(){
        cout<<"Delivering cargo by LAND in a box\n";
    }
};

class Ship : public IVehicle {
public:
    void deliver() {
        cout << "Delivering cargo by SEA in a shipping container.\n";
    }
};

//The Factory Interface
class Logistics{
public: 
   virtual IVehicle* createTransport()=0;
   
   void planDelivery(){
       IVehicle* transport=createTransport();
       cout<<"Planning delivery...\n";
       transport->deliver();
   }
};

class RoadLogistics:public Logistics{
    public:
    IVehicle* createTransport(){
        return new Truck();
    }
}; 

class SeaLogistics:public Logistics{
    public:
    IVehicle* createTransport(){
        return new Ship();
    }
}; 

int main(){
    cout<<"Client ask for road delivery\n";
    Logistics* roadApp=new RoadLogistics();
    roadApp->planDelivery();

    cout<<"\nClient ask for sea delivery\n";
    Logistics* seaApp=new SeaLogistics();
    seaApp->planDelivery();
    
    return 0;
}