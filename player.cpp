// player.cpp - implementation file for the player class
#include <iostream>
#include <cctype> // for toupper function
#include "player.h"

Player::Player()
{               // constructor definition
    hearts = 3; // initialize hearts to 3
    money = 0;  // initialize money to 0
    row = 0;    // initialize row coordinate to 0
    col = 0;    // initialize col coordinate to 0
}

// getter methods
int Player::getHearts() const { return hearts; } // return number of hearts
int Player::getMoney() const { return money; } // return amount of money
int Player::getRow() const { return row; } // return row coordinate
int Player::getCol() const { return col; } // return col coordinate

// setters
void Player::setPosition(int r, int c)
{ // set new given position
    row = r; 
    col = c;
}

void Player::addMoney(int amount)
{ // add money to current balance
    money += amount;
}

void Player::loseHeart()
{ // decrement hearts by one
    hearts--;
}

void Player::resetHearts()
{ // reset hearts to initial value
    hearts = 3;
}

void Player::move(char direction)
{ // move player in specified direction
    switch (toupper(direction))
    { // convert direction to uppercase
    case 'W':
        row--;
        break; //  up
    case 'S':
        row++;
        break; // down
    case 'A':
        col--;
        break; // left
    case 'D':
        col++;
        break; // right
    }
}

void Player::displayStats() const
{ // display player stats
    std::cout << "Hearts: " << hearts << " | Money: $" << money << std::endl;
}
