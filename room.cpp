// room.cpp - implementation file for the Room class
#include "room.h"

Room::Room()
{                                                        // room constructor
    openTop = openBottom = openLeft = openRight = false; // set all sides to be closed by default
    visited = false;                                     // initialize visited status to false
    item = nullptr;                                      // initialize item pointer to nullptr
    monster = nullptr;                                   // initialize monster pointer to nullptr
}

void Room::setOpenTop(bool value) { openTop = value; } // setters for each side of the room
void Room::setOpenBottom(bool value) { openBottom = value; }
void Room::setOpenLeft(bool value) { openLeft = value; }
void Room::setOpenRight(bool value) { openRight = value; }

bool Room::isOpenTop() const { return openTop; } // getters for each side of the room
bool Room::isOpenBottom() const { return openBottom; }
bool Room::isOpenLeft() const { return openLeft; }
bool Room::isOpenRight() const { return openRight; }

bool Room::isVisited() const { return visited; }       // check if the room has been visited
void Room::setVisited(bool value) { visited = value; } // set the visited status of the room

Item *Room::getItem() const { return item; }          // check what item is in the room
void Room::setItem(Item *newItem) { item = newItem; } // set the item in the room

Monster *Room::getMonster() const { return monster; }                // check what monster is in the room
void Room::setMonster(Monster *newMonster) { monster = newMonster; } // set the monster in the room
