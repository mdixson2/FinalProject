#ifndef ENEMY_H
#define ENEMY_H
using namespace std;



class Enemy{

  //not sure how we want to handle enemies
  public:
    Enemy();
    void EncounterEnemy();
    void PrintHealth();
    void PrintName();
    void PrintAttackStyle();
    void PrintMaxHit();
    void fight(Player&);

  private:
    string name;
    int health;
    string attackstyle;
    int maxhit;

};

Enemy::Enemy()
{
  srand (time(NULL));
  // 1 = Melee, 2 = Ranged, 3 = Magic
  int randomnum = rand() % 3 + 1;

  name = "Boss Name";
//  cout << "Boss = " << name << '\n';

  if (randomnum == 1)
    attackstyle = "Melee";
  else if (randomnum == 2)
    attackstyle = "Ranged";
  else if (randomnum == 3)
    attackstyle = "Magic";
  
//  cout << "Attackstyle = " << attackstyle << '\n';

  // Temporary health value
  health = 200;
//  cout << "Health = " << health << '\n';
  
  if (attackstyle == "Melee")
    maxhit = 5;
  else if (attackstyle == "Ranged")
    maxhit = 15;
  else if (attackstyle == "Magic")
    maxhit = 25;

//    cout << "Maxhit = " << maxhit << '\n';
}

// Printing information when encountering boss (some are temporary for testing)
void Enemy::EncounterEnemy()
{
  PrintName();
  PrintHealth();
  PrintAttackStyle();
  PrintMaxHit();
}

void Enemy::PrintHealth()
{
  cout << "Remaining Health: " << health << '\n';
}

void Enemy::PrintName()
{
  cout << "You have encountered " << name << "!\n";
}

void Enemy::PrintAttackStyle()
{
  cout << "Attack Style: " << attackstyle << '\n'; 
}

void Enemy::PrintMaxHit()
{
  cout << "Max Hit: " << maxhit << '\n';
}

void Enemy::fight(Player &p)
{
  char answer;


  cout << "A monster huddles in the corner. It hears you enter the room/nand charges at you.";
  cout << endl << "What do you do?" << endl;
  cout << "Fight it! (f) OR Be a coward and close the door. (r)" << endl;
  
  cin >> answer;

  while(answer != 'f' && answer != 'r')
  {
    cout << "Enter 'f' to fight the monster or 'r' to run away." << endl;
    cin >> answer;
  }
  if(answer == 'r')
  {
    p.position = p.last_room_index;
    cout << "You quickly shut the door with cowardice, but you have only wasted time." << endl << endl;
    cout << "You are still in Room " << p.position << ". Your movement options are the same." << endl;
    return;  
  }

  if(answer == 'f')
  {
    cout << "You courageously start a face the monster!" << endl << "GOOD LUCK!" << endl << endl;

  bool retreat = false;
  
  while(health > 0)
  {
      char move;
      
      cout << "You move! Your options are: " << endl;
      cout << "Attack with your fists! (n)" << endl;
      cout << "Use a item! (i)" << endl;
      cout << "Make a 'tactical' retreat! (r)" << endl;
      cin >> move;


      switch(move)
       {
          case('n'):
            cout << "You attack with your fists!" << endl;
            cout << "You deal 20 damage!" << endl;
            health -= 20;
            break;

          case('i'):
            /*if(p.inventory.size() == 0)
            {
              cout << "You  don't have any items!" << endl;
              break;

            }*/
              p.attack = 0;
              p.useItem();
              health -= p.attack;

              break;
            
          case('r'):
            cout << "You retreat! Were you scared or almost dead? Who knows?" << endl;
            retreat = true;
            p.position = p.last_room_index;
            break;
       }
      if(retreat) break;
      
      cout << endl << "The monster attacks!" << endl;

      int damage = maxhit - rand() % 5;
      p.health -= damage;
      cout << "You took " << damage << " damage! Ouch!!!" << endl;
      
      cout << "Your health: " << p.health << endl;
      PrintHealth();
      cout << "__________________________" << endl << endl;
       
  }
  if(retreat) return;

  cout << "The monster vanishes in a puff of smoke. You have won!" << endl;
  cout << "GAIN 5000 POINTS" << endl;
  p.points += 5000;



  }

}

#endif