//Final Project 
//Making a dungeon crawler
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <string>
#include <math.h>
#include <stdio.h>
#include "randommap.h"
#include "player.h"
#include "player.cpp"
#include "enemy.h"
#include "item.h"

using namespace std;

// Main
int main() {

  srand (time(NULL));
  Items it;

  char input;
  char difficulty;
  char m = 'P';
  vector <Room> grid;
  vector<int> roomTypes = CreateRandomMap();
  grid.resize(25);

  for(int i = 0; i < grid.size(); i++){
    grid[i].roomNum = i;
    grid[i].type = roomTypes[i];
    if (roomTypes[i] == 0)
      grid[i].typestring = "Start";
    if (roomTypes[i] == 1)
      grid[i].typestring = "End";
    if (roomTypes[i] == 2)
      grid[i].typestring = "Boss";
    if (roomTypes[i] == 3)
      grid[i].typestring = "Empty";
    if (roomTypes[i] == 4)
      grid[i].typestring = "Treasure";
    if (roomTypes[i] == 5)
      grid[i].typestring = "Item";
  }

  //startup options and game tutorial
 cout << "You wake up dazed on a cold, barren stone floor. Your back aches from the uneven bumps and cracks that you were once laying on. Observing your surroundings, you notice you’re in another generic dungeon crawler game. How typical! As these games tend to go you must find a way out of the walls that confine you by any means necessary. Minimizing moves and maximizing health will ensure you get the highest score possible! The dungeon you inhabit features a bounty of traps, enemies, and puzzles. You can move in any of the cardinal directions as long as there is a room there. You can show your current inventory with I and if there is an item to interact with using the command ___ ___ to use an item in your inventory. Using P will allow you see you current health and points.\n Enter ‘B’ to begin and best of luck to you traveller!" << endl;
  cin >> input;
  while(input != 'B'){
    cout << "PLEASE ENTER B TO BEGIN:";
    cin >> input;
  }
  
  cout << "CHOOSE A DIFFICULTY:" << endl << "E  M  H " << endl;
  cin >> difficulty;

  while(difficulty != 'E' && difficulty != 'M' && difficulty != 'H'){
    cout << "PLEASE ENTER E M H: ";
    cin >> difficulty;
  }
  cout << '\n'; 
  Player p(difficulty);
  cout << "PLAYING ON " << difficulty << "\n";
  //p.nextMove(m);

int x = sqrt(grid.size());

  int exit_room;
  for(int i = 0; i < grid.size(); i++)
  {
      if(grid[i].type == 1)
      {
        exit_room = i;
        break;
      }
  }
  cout << endl << "Exit is room " << exit_room << endl;
  while(true){

    cout << "\nYou are in Room Number: " << p.position << endl;
    cout << "This room is type: " << grid[p.position].typestring << endl;
    if(grid[p.position].visited == true)
      cout << "You've been here before" << endl;

    if(grid[p.position].type == 1){

      int point_rooms_left = 0;
      char cont = 'x';
      bool exit;
      
      //Get number of treasure rooms
      for(int i = 0; i < grid.size(); i++)
      {
        if(grid[i].type == 4 && grid[i].visited == false) point_rooms_left++;
      }

       cout << endl << "CONGRATULATIONS! YOU FOUND THE WAY OUT!" << endl;
       cout << "You can chose to leave now or keep exploring." << endl;
       cout << "Treasure rooms left: " << point_rooms_left << endl;
       cout << "Continue exploring? (y/n)" << endl;

       cin >> cont; 

       //Check input and exit or continue
       while(true)
       {
         if(cont == 'y') 
         {
           cout << "GOOD LUCK!" << endl;
           exit = false;
           break;
         }

         if(cont == 'n')
        {
          exit = true;
          break;
        }

        cin >> cont;
       }

       if(exit) break;

    grid[p.position].visited = true;
    }
    else if(grid[p.position].type == 2 && grid[p.position].visited == false){
      //boss or enemy text
      //interaction option
      Enemy boss;
      boss.EncounterEnemy();
      boss.fight(p);
      
      grid[p.position].visited = true;
    }
    else if(grid[p.position].type == 3){
      cout << "Nothing happened..." << endl;
      grid[p.position].visited = true;
    }
    else if(grid[p.position].type == 4 && grid[p.position].visited == false){

      //Calculate the number of points you get and add them to the player's total
      int value;
      srand (time(NULL));
      value = rand() % 2000 + 2000;
      p.points += value;
     
      cout << "You found a treasure room!" << endl;
      cout << "It's worth " << value << " points!!" << endl;

      grid[p.position].visited = true;
    }
    else if(grid[p.position].type == 5 && grid[p.position].visited == false){
      //item room
      
      int RNG = rand() % 23;

      it.mit = it.item.begin();

      advance(it.mit, RNG);

      cout << "You have recieved a " << it.mit->second << endl;

      p.inventory.insert(pair<vector<int>, string>(it.mit->first, it.mit->second));

      grid[p.position].visited = true;
    }

   if(p.position - sqrt(grid.size()) > 0){
     cout << "You can move up (Press w): ";
   }
   if(p.position + sqrt(grid.size()) < grid.size()){
     cout << "You can move down (Press s): "; 
   }
   if(p.position % x != 0){
     cout << "You can move left(Press a): ";
   }
   if(p.position % x != (x-1)){
     cout << "You can move right(Press d): ";
   }
   cout << endl;
   cin >> m;
   if(m == 'q'){
     break;
   }
   p.nextMove(m);

   cout << "__________________________" << endl << endl;
  }
  
    
 p.endPoints();  
}


