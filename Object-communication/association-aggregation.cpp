#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Player{
    private:
    string name;
    public:
    Player(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
};

class Team{
   private:
   string teamname;
   public:
   vector<Player*> players; // pointer because 
   Team(string name){
    this->teamname=name;
   }
   void addPlayer(Player* p){
    players.push_back(p);
   }
   void PrintPlayer(){
    cout<<"Players in "<<teamname<<":\n";
    for(Player* p : players){
        cout<<p->getName()<<"\n";
    }
   }
   //cannot delete player here
   ~Team(){
      cout<<"Team "<<teamname
<<" is disabled"<<endl;
   }
};

int main(){
    Player* p1=new Player("Nilay");
    Player* p2=new Player("Lucky");
    Player* p3=new Player("Apurv");

    Team team1=Team("Team");
    team1.addPlayer(p1);
    team1.addPlayer(p2);
    team1.addPlayer(p3);

    team1.PrintPlayer();

    delete p1; 
    delete p2;
    delete p3;

    return 0;
}