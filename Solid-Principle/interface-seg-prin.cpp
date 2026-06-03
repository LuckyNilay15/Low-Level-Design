#include <iostream>
using namespace std;

class IPrinter{
    public:
    virtual void print()=0;
};

class IScanner{
    virtual void scan()=0;
};

class BasicPrinter:public IPrinter{
    public:
    void print(){
        cout<<"Basic printing";
    }
};

class MultiFunctionPrinter:public IPrinter,public IScanner{
    public:
    void print(){
        cout<<"Multi-function printing";
    }
    void scan(){
        cout<<"Multi-function scanning";
    }
};

int main(){
    BasicPrinter bp;
    MultiFunctionPrinter mfp;
    bp.print();
    mfp.print();
    mfp.scan();
    return 0;
}