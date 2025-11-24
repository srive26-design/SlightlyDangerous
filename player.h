// player.h - header file for the Player class

#ifndef PLAYER_H // if PLAYER_H is not defined, define it, if defined, skip to the end
#define PLAYER_H // define PLAYER_H

#include <string> // include string library for using string data type

class Player
{                     // player class declaration
private:              // private access specifier so members are not accessible from outside the class
    int hearts;       // integer variable for hearts
    int money;        // integer variable for money
    int row, col;     // integer variables for player coordinates
    
public:       // public access specifier so members are accessible from outside the class
    Player(); // constructor

    // to read data (getters)
    int getHearts() const; // returns number of hearts
    int getMoney() const;  // returns amount of money
    int getRow() const;    // returns row coordinate
    int getCol() const;    // returns col coordinate
    // to change data (setters)
    void setPosition(int r, int c); // set new position
    void addMoney(int amount);       // add money
    void loseHeart();                // lose a heart
    void resetHearts(); // reset hearts to initial value

    // movement helper
    void move(char direction); // move player in specified direction

    // display info about player
    void displayStats() const;
};

#endif
