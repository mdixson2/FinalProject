#include "player.h"

Player::Player(char difficulty)
{
  if(difficulty == 'E')
  {
    health = 500;
    points = 0;
  }

  else if (difficulty == 'M')
  {
    health = 400;
    points = 1000;
  }

  else if (difficulty == 'H')
  {
    health = 300;
    points = 2000;
  }

  moves = 1;
  attack = 20;

}
void Player::status()
{
  cout << "\nHEALTH: " << health << '\n';
  cout << "POINTS: " << points << '\n';
  cout << "MOVES: " << moves << '\n';
}

void Player::nextMove(char m){

  if(m == 'p'){
    status();
  }
  if(m == 'i' && inventory.size() > 0){
    for(iit = inventory.begin(); iit != inventory.end(); iit++){
     // if(i == inventory.size()-1){
    //  cout << inventory[i] << endl;
    //    break;
   //   }
      cout << iit->second << " " << endl;
    }
  }

if(m == 'u' && inventory.size() > 0){

  int itemChoice;
  bool used = false;

  cout << "Which item would you like to use?" << endl;
  for(iit = inventory.begin(); iit != inventory.end(); iit++){
      int i = 0;
      cout << "item " << i << ": " << iit->second << '\n';
      i++;
  }    
    while(cin >> itemChoice){

      for(iit = inventory.begin(); iit != inventory.end(); iit++){
        int i = 0;
      
        if(i == itemChoice && iit->first[0] == 1){

          cout << "You have used " << iit->second << endl;
          cout << "You have gained " << iit->first[1] << " health!!" << endl;
          
          health += iit->first[1];
          
          cout << "Your new health total is: " << health << endl;
          used = true;
        } 
        if(i == itemChoice && iit->first[0] == 0){

          cout << "You cannot use " << iit->second << " outside of battle" << endl;

        }

      //trying to find a way to prevent items from being used more than once
      
      if(used)
        inventory.erase(iit);

      i++;
      if(used == false && i == itemChoice && iit->first[0] == 1)
        cout << itemChoice << " is not a valid item index" << endl;
      }
      

    break;

    }
}

  last_room_index = position; //Keep track of what the last room is for combat

  if(m == 'w' && position > 4){
    cout << "You have moved up!" << endl;
    position = position - 5;
    moves++;
  }
  if(m == 's' & position < 20){
    cout << "You have moved down!" << endl;
    position = position + 5;
    moves++;
  }
  if(m == 'a' && position%5 != 0){
    cout << "You have moved the left!"<< endl;
    position = position - 1;
    moves++;
  }
  if(m == 'd' && (position+1)%5 != 0){
    cout << "You have moved to the right" << endl;
    position = position + 1;
    moves++;
  }
}

void Player::endPoints()
{
  int end;
  
  end = (health * 1.33 + points);

  cout << "Total Points Earned: " << end << '\n';

}

void Player::useItem()
{
  int itemChoice;
  bool used = false;
  //Error check in fight

  if(inventory.empty()){

    cout << "You have no items to use.... Tough luck" << endl;

  }
  else{

  
  cout << "Which item would you like to use?" << endl;
  for(iit = inventory.begin(); iit != inventory.end(); iit++){
      int i = 0;
      cout << "item " << i << ": " << iit->second << '\n';
      i++;
  }    
    while(cin >> itemChoice){

      for(iit = inventory.begin(); iit != inventory.end(); iit++){
        int i = 0;
      
        if(i == itemChoice && iit->first[0] == 1){

          cout << "You have used " << iit->second << endl;
          cout << "You have gained " << iit->first[1] << " health!!" << endl;
         
          health += iit->first[1];

          cout << "Your new health total is: " << health << endl;
          used = true;
        } 
        if(i == itemChoice && iit->first[0] == 0){

          cout << "You have equipped " << iit->second << endl;
          cout << "You have gained " << iit->first[1] << " damage!!" << endl;

          if(attack != 20)
          attack = 20;

          attack += iit->first[1];

          cout << "Your new attack stat is: " << attack << endl;
          used = true;
        } 
      //trying to find a way to prevent items from being used more than once
      if(used)
        inventory.erase(iit);

      i++;

      if(used == false && i == itemChoice && iit->first[0] == 1){
        cout << itemChoice << " is not a valid item index" << endl;
       }



      }
      

    break;

    }

  }
          //Apply item effects
}        
