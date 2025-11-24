// room.h - header file for the Room class
#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include "monster.h"
#include <string>

class Room
{ // Room class declaration
private:
    bool openTop, openBottom, openLeft, openRight; // bool value for which sides have hallways
    bool visited;                                  // bool value forwhether the room has been visited
    Item *item;                                    // pointer to the item in the room (if any) nullptr if none
    Monster *monster;                              // pointer to the monster in the room

public:
    Room(); // constructor

    // getter functions for each side of the room
    bool isOpenTop() const; // returns true if there's a hallway on (top/bottom/left/right) of the room
    bool isOpenBottom() const;
    bool isOpenLeft() const;
    bool isOpenRight() const;

    // setter functions for each side of the room
    void setOpenTop(bool value); // to mark a hallway (top/bottom/left/right) as open or closed
    void setOpenBottom(bool value);
    void setOpenLeft(bool value);
    void setOpenRight(bool value);

    bool isVisited() const;      // checks if the room has been visited
    void setVisited(bool value); // sets the visited status of the room

    Item *getItem() const;                // gets the item in the room
    void setItem(Item *newItem);          // sets the item in the room to new item
    Monster *getMonster() const;          // gets the monster in the room
    void setMonster(Monster *newMonster); // sets the monster in the room to new monster
};

#endif
