#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

using namespace std;

class Items{

public:

map <vector<int>, string> item;
map <vector<int>, string>::iterator mit;

Items(){

 
  string weapons[7] = {"Sword", "Club", "Hammer", "Axe", "Board", "Shank", "Stick"};
  string health[7] = {"Med Kit", "Bandage", "Mystery Serum", "Water", "Rations", "Spoiled Food", "Gauze"};
  string random = "Gift";

  srand (time(NULL));

  int damage[7] = {20, 17, 15, 12, 7, 5, 1};
  int healing[7] = {100, 15, rand() % 75, 20, 25, 1, 5};
  int randGift = rand() % 2;

  for(int i = 0; i <= 24; i++){
    
    int randNum = rand() % 10;
    int randChoice = rand() % 7;
    //the weapon type and it's stat (either health or damage) are stored in the vector Type Stat
    //if TypeStat[0] = 0 represents weapon
    //if Typestat[0] = 1 represents health
    //
    //TypeStat[1] corresponds to how much healing or damage an item does
    vector<int> TypeStat;

    if(randNum < 4){
      TypeStat.push_back(0);
      TypeStat.push_back(damage[randChoice]);
      item.insert(pair<vector<int>, string>(TypeStat, weapons[randChoice]));
    }
    else if(randNum >= 4 && randNum <= 7){
      TypeStat.push_back(0);
      TypeStat.push_back(healing[randChoice]);
      item.insert(pair<vector<int>, string>(TypeStat, weapons[randChoice]));
    }
    else{

      //the gift item can heal or deal damage
      if(randGift == 0){
        TypeStat.push_back(0);
        TypeStat.push_back(damage[randChoice]);
        item.insert(pair<vector<int>, string>(TypeStat, random+" - Weapon"));
      
      }
      else{
        TypeStat.push_back(1);
        TypeStat.push_back(healing[randChoice]);
        item.insert(pair<vector<int>, string>(TypeStat, random+" - Health"));
        
      }
    }

  }


}

};


#endif
