#include <iostream>
#include <string>

using namespace std;

class IDatabase{
    public:
    virtual void requestData()=0;
};

class RealDatabase:public IDatabase{
    private:
    static RealDatabase* instance;
    RealDatabase(){
        cout<<"[SYSTEM]:Booting up massive Real Database...Please wait...\n";
        cout<<"[SYSTEM]:Connected to 500 servers.\n";
    }
    public:
    static RealDatabase* getInstance(){
        if(instance==NULL){
            instance=new RealDatabase();
        }
        return instance;
    }
    void requestData(){
        cout<<"RealDatabase: Returning the actual sensitive corporate data.\n";
    }
};

class DatabaseProxy:public IDatabase{
    private:
    RealDatabase* actualDatabase;
    string userRole;
    public:
    DatabaseProxy(string role){
        userRole=role;
        actualDatabase=NULL;
    }

    void requestData(){
        if(userRole!="ADMIN"){
            cout<<"Proxy Error: Access Denied for role:"<<userRole<<endl;
            return ;
        }
        if(actualDatabase==NULL){
            cout<<"Proxy: Adminauthorized. Booting up real database for the first time...\n";
            // actualDatabase=new RealDatabase();
            actualDatabase=RealDatabase::getInstance();
        }
        actualDatabase->requestData();
    }
};
RealDatabase* RealDatabase::instance = NULL;
int main(){
    cout<<"---Attempt 1:Normal User---\n";
    IDatabase* guestDB=new DatabaseProxy("GUEST");
    guestDB->requestData();
    cout<<"Attempt 2 :Admin User---\n";
    IDatabase* adminDB=new DatabaseProxy("ADMIN");
    cout<<"Clicking download button...\n";
    adminDB->requestData();
    cout<<"Clicking download button again...\n";
    adminDB->requestData();
    return 0;
}