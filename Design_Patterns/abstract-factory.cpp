#include <iostream>
using namespace std;

class IVehicle{
    public:
    virtual void drive()0;
};

class IRoutePlanner{
    public:
     virtual void mapFastestRoute()=0;
};

class Truck:public IVehicle{
    public:
    void drive(){
        cout<<"Driving on the highway";
    }
};

class HighwayPlanner:public IRoutePlanner{
    public:
    void mapFastestRoute(){
        cout<<"Plotting route avoiding traffic lights";
    }
};

class Ship:public IVehicle{
    public:
    void drive(){
        cout<<"Sailing accross the ocean waves";
    }
};

class OceanPlanner:public IRoutePlanner{
    public:
    void mapFastestRoute(){
        cout<<"Plotting route avoiding shallow reefs";
    }
};
class Plane:public IVehicle{
    public:
    void drive(){
        cout<<"Flying through the sky";
    }
};

class AirRoutePlanner:public IRoutePlanner{
    public:
    void mapFastestRoute(){
        cout<<"Plotting route avoiding storms";
    }
};

class ILogisticsFactory{
    public:
    virtual IVehicle* createVehicle()=0;
    virtual IRoutePlanner* createRoutePlanner()=0;
};

class RoadLogisticsFactory:public ILogisticsFactory{
    public:
    IVehicle* createVehicle(){
        return new Truck();
    }
    IRoutePlanner* createRoutePlanner(){
        return new HighwayPlanner();
    }
};

class SeaLogisticsFactory:public ILogisticsFactory{
    public:
    IVehicle* createVehicle(){
        return new Ship();
    }
    IRoutePlanner* createRoutePlanner(){
        return new OceanPlanner();
    }
};

class AirLogisticsFactory:public ILogisticsFactory{
    public:
    IVehicle* createVehicle(){
        return new Plane();
    }
    IRoutePlanner* createRoutePlanner(){
        return new AirRoutePlanner();
    }
};

void planDelivery(ILogisticsFactory* factory){
    IVehicle* myVehicle=factory->createVehicle();
    IRoutePlanner* planner=factory->createRoutePlanner();
    planner->mapFastestRoute();
    myVehicle->drive();
    cout<<"Delivery completed safely";
}

int main(){
    cout<<"Starting Land operation";
    ILogisticsFactory* roadFactory=new RoadLogisticsFactory();
    planDelivery(roadFactory);

    //output: Plotting route avoiding traffic... Driving on highway.
    cout<<"\nStarting sea operations";
    ILogisticsFactory* seaFactory=new SeaLogisticsFactory();
    planDelivery(seaFactory);
     // Output: Plotting route avoiding reefs... Sailing across ocean.

    ILogisticsFactory* airFactory=new AirLogisticsFactory();
    planDelivery(airFactory);
    return 0;
}

