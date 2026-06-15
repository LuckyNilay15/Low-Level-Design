#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class IObserver{
    public:
    virtual void update(float temp,float humidity)=0;
    virtual ~IObserver() {}
};

class PhoneDisplay: public IObserver{
    private:
    string username;
    public:
    PhoneDisplay(string name) {username=name;}
    void update(float temp,float humidity){
        cout<<"Phome-"<<username<<"Temp is now "<<temp<<"F Humidity: "<<humidity<<endl;
    }
};

class WindowDisplay:public IObserver{
    public:
    void update(float temp,float humidity){
        cout << "[Window LCD]: WARNING! Temperature changed to " << temp << "F.\n";
    }
};

class WeatherStation{ // totally decoupled class
    private:
    vector<IObserver*> subscribers; //AHA MOMENT
    float temperature;
    float humidity;

    public:
    void registerObserver(IObserver* o){
        subscribers.push_back(o);
        cout<<"System: A new device subscribed to Weather updates"<<endl;
    }
    
    void removeObserver(IObserver* o){
        auto it=find(subscribers.begin(),subscribers.end(),o);
        if(it!=subscribers.end()){
            subscribers.erase(it);
            cout<<"System: A device UN-subscribed from updates"<<endl;
        }
    }
    void notifyObservers(){
        for(int i=0;i<subscribers.size();i++){
            subscribers[i]->update(temperature,humidity);
        }
    }

    void setMeasurements(float newTemp,float newHumidity){
        cout<<"WeatherStation sensors detecting changes"<<endl;
        temperature=newTemp;
        humidity=newHumidity;
        notifyObservers();
    }
};

int main(){
    WeatherStation station;

    IObserver* luckyPhone=new PhoneDisplay("lucky");
    IObserver* windowLCD=new WindowDisplay();
    IObserver* momPhone=new PhoneDisplay("mom");

    station.registerObserver(luckyPhone);
    station.registerObserver(windowLCD);
    
    station.setMeasurements(80.f,65.0f);
    station.registerObserver(momPhone);
    station.removeObserver(luckyPhone);
    station.setMeasurements(78.0f,90.0f);

    delete luckyPhone;
    delete windowLCD;
    delete momPhone;
    return 0;
}