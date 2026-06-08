#include <iostream>
#include <string>

using namespace std;

class ThirdPartyChartLibrary{
    public:
    void analyzeData(string jsonData){
        cout << "Analyzing data using third party library: " << jsonData << endl;
    }
};

class IAnalyticsTarget{
    public:
    virtual void processData(string xmlData)=0;
};

class AnalyticsAdapter: public IAnalyticsTarget{
    private:
    ThirdPartyChartLibrary* library;
    public:
    AnalyticsAdapter(ThirdPartyChartLibrary* lib){
        library=lib;
    }

    void processData(string xmlData){
        cout<<"Adapter recieved XML: "<<xmlData<<endl;
        cout<<"Adapter: Translating XML to JSON";
        string jsonData="{translated json from "+xmlData+"}";
        library->analyzeData(jsonData);
    }
};

int main(){
    cout<<"--Client Application Started--";
    ThirdPartyChartLibrary *alienLibrary=new ThirdPartyChartLibrary();
    IAnalyticsTarget* myAnalytics=new AnalyticsAdapter(alienLibrary);
    string myBusinessData="<xml>Sales Data</xml>";
    myAnalytics->processData(myBusinessData);
    return 0;    
}