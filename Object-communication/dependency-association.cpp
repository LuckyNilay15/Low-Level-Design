#include <iostream>
#include <string>
using namespace std;


class PaymentProcess{
  // this is payment process and upon request
   public:
   bool charge(double amount) {
        std::cout << "Charging $" << amount << " via Payment Gateway...\n";
        return true;
    }
};

class DatabaseLogger{
    // this class is only responsible for logging and evertime
    public:   
    void log(string message){
        //logger->log(message)
        cout<<"[LOG]: "<<message<<endl;
    } 
};


class Order{
    private:
    DatabaseLogger* logger;
    double amount;
    public:
    Order(DatabaseLogger* logger,double val){
        this->logger=logger; //logger will log with association
        this->amount=val;
        // paymentprocess hoga dependency 
    }
    void checkout(PaymentProcess& processor){
        logger->log("Checkout started for amount");
        bool success=processor.charge(amount);
        if(success){
            logger->log("Payment completed successfully");
        }else{
            logger->log("Payment failed");
        }
    }
};

