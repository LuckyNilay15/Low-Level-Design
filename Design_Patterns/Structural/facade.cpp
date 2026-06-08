#include <iostream> 
using namespace std;

class TV{
   public:
   void turnOn(){
      cout<<"TV: Turning on"<<endl;
   }
   void setInputChannel(){
      cout<<"TV: Setting input to HDMI 1...\n";
   }
};

class SoundSystem{
    public:
    void turnOn(){
        cout<<"Audio: Powering up surround sound...\n";
    }
    void setVolume(int level){
        cout<<"Audio: Setting volume to"<<level<<".\n";
    }
};

class SmartLights{
    public:
    void dim(){
        cout<<"Lights: Dimming to 20% for movie mode...\n";
    }
};

class DVDPlayer{
    public:
    void turnOn(){
        cout<<"DVD:Powering up...\n";
    }
    void playMovie(){
        cout<<"DVD: Playing the movie! Enjoy!\n";
    }
};

class HomeTheaterFacade{
    private:
    TV* tv;
    SoundSystem* audio;
    SmartLights* lights;
    DVDPlayer* dvd;
    public:
    HomeTheaterFacade(TV* t,SoundSystem* a,SmartLights* l,DVDPlayer* d){
        tv=t;
        audio=a;
        lights=l;
        dvd=d;
    }
    void watchMovie(){
        cout<<"--GETTING READY TO WATCH A MOVIE---\n";
        lights->dim();
        tv->turnOn();
        tv->setInputChannel();
        audio->turnOn();
        audio->setVolume(50);
        dvd->turnOn();
        dvd->playMovie();
        cout<<"ENJOY THE SHOW!\n";
    }
};

int main(){
    TV* myTv=new TV();
    SoundSystem* myAudio=new SoundSystem();
    SmartLights* myLights=new SmartLights();
    DVDPlayer* myDvd=new DVDPlayer();

    HomeTheaterFacade* simpleRemote=new HomeTheaterFacade(myTv,myAudio,myLights,myDvd);
    simpleRemote->watchMovie();
    return 0;
}