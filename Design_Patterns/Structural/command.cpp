#include <iostream>
#include <stack>
#include <string>

using namespace std;

class SmartLight{
  public:
  void turnOn(){
      cout<<"Light Bulb: Shining brightly"<<endl;
  }
  void turnOff(){
      cout<<"Light Bulb: Darkness"<<endl;
  }
};

class ICommand{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};

class RemoteControl{
   private:
   ICommand* button;
   stack<ICommand*> history;

   public:
   void setCommand(ICommand* c){
      button=c;
   }

   void pressButton(){
      if(button!=NULL){
        button->execute();
        history.push(button);
      }
   }
   void pressUndo(){
    if(!history.empty()){
        ICommand* lastCommand=history.top();
        history.pop();
        lastCommand->undo();
    }else{
        cout<<"No commands to undo"<<endl;
    }
   }
};

class LightOnCommand: public ICommand{
    private:
    SmartLight* light;

    public:
    LightOnCommand(SmartLight* l ){light=l;} 
    void execute(){
        light->turnOn();
    }
    void undo(){
        light->turnOff();
    }
};

int main(){
    SmartLight* light=new SmartLight();
    ICommand* switchLightOn=new LightOnCommand(light);

    RemoteControl* remote=new RemoteControl();
    remote->setCommand(switchLightOn);
    remote->pressButton();
    remote->pressUndo();

    delete light;
    delete switchLightOn;
    delete remote;
    return 0;
    
}