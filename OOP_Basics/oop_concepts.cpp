#include <iostream>
#include <string>

using namespace std;

class Account{
    protected:
        string ownerName;
    public:
    virtual void calculateInterest()=0;
    virtual void deposit(double bal) = 0;
    virtual void withdraw(double bal) = 0;
    virtual double getbalance() = 0;
    virtual ~Account() {} 
};

class SavingAccount : public Account{
    private:
        double balance;
    public:
        SavingAccount(string name, double bal){
            ownerName=name;
            balance=bal;
        }
    // Polymorphism: overriding base class methods  
    double getbalance() {return balance;}
    void setbalance(double bal){
        balance=bal;
    }   
    void deposit(double bal){
        balance+=bal;
    }  
    void withdraw(double bal){
        if(bal>balance) return ;
        balance-=bal;
    } 
    void calculateInterest(){
        balance+=balance*0.05;
    }
};   

int main(){
    Account *acc=new SavingAccount("Lucky",1000);
    acc->deposit(100);
    acc->withdraw(10000);
    acc->calculateInterest();
    cout<<acc->getbalance();
    delete acc; // Always clean up dynamic memory in C++
    return 0;
}

