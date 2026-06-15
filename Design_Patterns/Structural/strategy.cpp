#include <iostream>
using namespace std;

class IRouteStrategy{
   public:
   virtual void calculateRoute()=0;
   virtual ~IRouteStrategy() {} 
};

class DrivingStrategy:public IRouteStrategy{
    public:
    void calculateRoute(){
        cout<<"Calculating route using driving strategy...\n";
    }  
};

class WalkingStrategy:public IRouteStrategy{
    public:
    void calculateRoute(){
        cout<<"Calculating route using walking strategy...\n";
    }  
};

class PublicTransitStrategy:public IRouteStrategy{
    public:
    void calculateRoute(){
        cout<<"Calculating route for transit";
    }
};

class Navigator{
    private:
    IRouteStrategy* currentStrategy;
    public:
    Navigator(IRouteStrategy* initialStrategy){
        currentStrategy=initialStrategy;
    }
    void setStrategy(IRouteStrategy* newStrategy){
        currentStrategy=newStrategy;
    }
    void buildRoute(){
        if(currentStrategy==NULL){
            cout<<"Error: No strategy set!";
            return ;
        }
        currentStrategy->calculateRoute();
    }
};

int main(){
    IRouteStrategy* drive=new DrivingStrategy();
    IRouteStrategy* walk=new WalkingStrategy();
    IRouteStrategy* subway=new PublicTransitStrategy();

    Navigator* myGps=new Navigator(drive);
    myGps->buildRoute();
    cout<<"\n---Changing to Walking---\n";
    myGps->setStrategy(walk);
    myGps->buildRoute();
    cout<<"\n---Changing to Subway---\n";
    myGps->setStrategy(subway);
    myGps->buildRoute();
    delete drive;
    delete walk;
    delete subway;
    delete myGps;
    return 0;
}