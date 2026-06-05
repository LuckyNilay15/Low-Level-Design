#include <iostream>
#include <string> 

using namespace std;

class ISoldier{
    public:
    virtual ISoldier* clone()=0;
    virtual void printDetails()=0;
};


class HeavySoldier:public ISoldier{
   private:
   string armorType;
   string weapon;
   int healthPoints;

   int* upgradeLevels;

   public:
   HeavySoldier(string armor, string wpn, int hp){
      armorType=armor;
      weapon=wpn;
      healthPoints=hp;
      upgradeLevels=new int[3];
      upgradeLevels[0]=1;
      cout<<"Heavy Soldier Created with Armor:"<<endl;
   }

    HeavySoldier(const HeavySoldier& original){
        this->armorType=original.armorType;
        this->weapon=original.weapon;
        this->healthPoints=original.healthPoints;
        this->upgradeLevels=new int[3];
        for(int i=0;i<3;i++){
            this->upgradeLevels[i]=original.upgradeLevels[i];
        }
        cout<<"Heavy Soldier Copied"<<endl;
    }

   ISoldier* clone(){
       return new HeavySoldier(*this);
   }

   void printDetails(){
      cout<<"Heavy soldier weapon:"<<weapon<<endl;
      cout<<"Heavy soldier armor:"<<armorType<<endl;
      cout<<"Heavy soldier health:"<<healthPoints<<endl;
   }
};


int main(){
    cout<<"Building the original prototype";
    HeavySoldier* originalPrototype-new HeavySoldier("Steel Armor","Machine Gun",200);
    originalPrototype->printDetails();

    cout<<"Player clicks 'Train 2 soldiers'---";
    ISoldier* clone1=originalPrototype->clone();
    ISoldier* clone2=originalPrototype->clone();

    cout<<"Clone 1:";
    clone1->printDetails();
    cout<<"Clone 2:";
    clone2->printDetails();

    return 0;
    
}

