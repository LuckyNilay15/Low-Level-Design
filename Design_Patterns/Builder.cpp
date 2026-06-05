#include <iostream>
#include <string>

using namespace std;

class Truck{
    public:
    string engine="Basic Engine";
    bool hasRefrigerator=false;
    bool hasArmor=false;
    string GPS="No GPS";

    void showSpecs(){
        cout<<"Truck SPECS";
        cout<<"Engine: "<<engine<<endl;
        cout<<"Refrigerator: "<<hasRefrigerator ? "YES" : "NO"<<endl;
        cout<<"Armor: "<<hasArmor ? "YES" : "NO"<<endl;
        cout<<"GPS: "<<GPS<<endl;
    }
};

class ITruckBuilder{
   public:
   virtual void buildEngine()=0;
   virtual void buildRefrigerator()=0;
   virtual void buildArmor()=0;
   virtual void buildGPS()=0;
   virtual Truck* getTruck()=0;
};

class RefrigeratedTruckBuilder:public ITruckBuilder{
    private:
    Truck* truck;
    public:
    RefrigeratedTruckBuilder(){
        truck =new Truck;
    }
    void buildEngine(){
        truck->engine="High-Torque Diesel v8";
    } 
    void buildCoolingSystem(){
        truck->hasRefrigerator=true;
    }
    void buildArmor(){
        truck->hasArmor=false;
    }
    void buildGPS(){
        truck->GPS="Standard GPS";
    }
    Truck* getResult(){
        return truck;
    }
};

class ArmoredTruckBuilder:public ITruckBuilder{
    private:
    Truck* truck;
    public:
    ArmoredTruckBuilder(){
        truck =new Truck;
    }
    void buildEngine(){
        truck->engine="High-Torque Diesel v8";
    } 
    void buildCoolingSystem(){
        truck->hasRefrigerator=false;
    }
    void buildArmor(){
        truck->hasArmor=true;
    }
    void buildGPS(){
        truck->GPS="Advanced GPS";
    }
    Truck* getResult(){
        return truck;
    }
};
int main(){
    cout<<"Dispatcher:We need a food delivery truck";
    ITruckBuilder* foodBuilder=new RefrigeratedTruckBuilder();
    foodBuilder->buildEngine();
    foodBuilder->buildCoolingSystem();
    foodBuilder->buildGPS();
    Truck* foodTruck=foodBuilder->getResult();
    foodTruck->showSpecs();
    cout<<"Dispatcher: we need a secure bank transport";

    ITruckBuilder* bankTruck=new ArmoredTruckBuilder();
    bankTruck->buildEngine();
    bankTruck->buildArmor();
    bankTruck->buildGPS();
    Truck* bankTruck=bankTruck->getResult();
    bankTruck->showSpecs();

    return 0;
}