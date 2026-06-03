#include <iostream>
#include <string>

using namespace std;

class Logger{
    private:

    static Logger* instance;
    Logger(){
        cout<<"Logger Object formed in Memory\n";
    }
    Logger(const Logger &);
    Logger& operator=(const Logger&);

    public:

    static Logger* getInstance(){
        if(instance==NULL){
            instance=new Logger();
        }
        return instance;
    }
    
    void log(string message){
        cout<<"LOG: "<<message<<endl;
    }
};

Logger* Logger::instance=NULL;

int main(){
    Logger* log1=Logger::getInstance();
    log1->log("First message");
    Logger* log2=Logger::getInstance();
    log2->log("Second message");
    return 0;
}
