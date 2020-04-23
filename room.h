#ifndef ROOM_H
#define ROOM_H

using namespace std;
//Graph from project 4 
class Room
{
    public:
       // int x;
       // int y;      //Coords
        //int weight; //This is basically the distance between two adj nodes
        //int distance;
        bool defeated;
        bool visited;
        string text; 
        vector< Room * > adj;
        //map<int, string> type;//This determines the type of room that will be generated

        string typestring;
        int type;
        int roomNum;
};

#endif
