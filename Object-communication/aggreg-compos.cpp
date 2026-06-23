#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Page{
    private:
    string content;
    int number;
    public:
    Page(int num,string cont){
        this->number=num;
        this->content=cont;
    }

    void printPage(){
        cout<<"Page Number: "<<number<<"Content:"<<content<<endl;
    }
    

};

class Document{
    private:
    string title;
    vector<Page> pages;
    public:
    Document(string title){
        this->title=title;
    }
    void addpage(int number,string content){
        pages.push_back(Page(number,content));
    }

    void printDocument(){
        cout<<"Document Title: "<<title<<endl;
        for(Page p : pages){
            p.printPage();
        }
    }

    ~Document() {
        std::cout << "Document '" << title << "' and all its pages are deleted.\n";
    }

};


int main(){
    Document* d=new Document("Notes");
    d->addpage(1,"Introduction");
    d->addpage(2,"Body");
    d->addpage(3,"Conclusion");

    d->printDocument();

    delete d;
    return 0;
}