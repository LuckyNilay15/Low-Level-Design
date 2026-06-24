#include<iostream>
#include<string>
using namespace std;

class NotificationSystem{ 
     public:
     virtual void send(const string & message)=0;
};

class EmailNotification:public NotificationSystem{
    public:
    void send(const string & message){
        cout<<"Sending the message via email "<<message<<endl;
    }
};

class SMSNotification:public NotificationSystem{
    public:
    void send(const string & message){
        cout<<"Sending the message via SMS "<<message<<endl;
    }
};

class AlertSystem{
    private:
    NotificationSystem* notify;
    public:
    AlertSystem(NotificationSystem* s){
        this->notify=s;
    }
    void triggerAlert(string& msg){
        notify->send(msg);
    }
};

int main(){
    EmailNotification emailNotifier;
    SMSNotification smsNotifier;

    // emailNotifier.send("Hello");

    AlertSystem alert1(&emailNotifier);
    AlertSystem alert2(&smsNotifier);

    string msg="Alert:";

    alert1.triggerAlert(msg);
    alert2.triggerAlert(msg);

    return 0;
}
