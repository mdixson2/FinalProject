#ifndef RANDOMMAP_H
#define RANDOMMAP_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> CreateRandomMap()
{
  vector <int> rooms;
  int n = 5;
  int startpos, endpos;

  srand (time(NULL));

  startpos = 0;
  endpos = rand() % 24 + 1;
  rooms.resize(n*n, -1);

  // The starting room is always at 0
  rooms[startpos] = 0;

  // Placing the end room
  rooms[endpos] = 1;

  // Randomly placing the rest of the rooms
  for (int i = 1; i < (n*n); i++)
  {
    if (rooms[i] != -1)
      continue;

    unsigned int roomtype;
    unsigned int prob;

    // Can be rooms 2, 3, or 4
    // 2 - Boss - 20% chance
    // 3 - Empty - 50% chance
    // 4 - Points - 30% chance
    prob = rand() % 10;
  
    // 0-2 (30%) - Empty
    if (prob <= 2)
      roomtype = 3;

    // 3-4 (20%) - Item Room
    if (prob >= 3 && prob <= 4)
      roomtype = 5;

    // 5-7 (30%) - Points
    if (prob >= 5 && prob <= 7)
      roomtype = 4;

    // 8-9 (20%) - Boss
    if (prob >= 8)
      roomtype = 2;

    rooms[i] = roomtype;
  }
  
  for (int i = 0; i < rooms.size(); i++)
  {
    cout << rooms[i];
  }
  cout << '\n';
return rooms;
}

#endif
