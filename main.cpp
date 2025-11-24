// main.cpp
#include <iostream>
#include <cctype> 
#include <cstdlib> 
#include <ctime> 

#include "player.h"
#include "room.h"
#include "item.h"
#include "monster.h"
#include "maze.h"
#include "minigame.h"
#include "animation.h"
#include "hud.h"
#include "utils.h"

int day = 1; // global day variable used in maze.cpp

int main()
{
    std::srand(static_cast<unsigned>(time(NULL))); // seed random time generator

    int quota[3] = {50, 200, 600}; // daily quotas
    bool running = true;            // game loop flag

    int menuResult = displayMenu(); // display menu, can go into rules or start game
    if (menuResult == 0) // if user selects exit option
    {
        return 0; // end program
    }

    system("cls"); // clear screen

    Maze maze(5, 5); // create maze object with dimensions 5x5
    Player player;   // create player object

    player.setPosition(2, 2); // center player

    maze.generateMaze(); // generate day 1 maze

    while (running) // while game loop flag is true
    {
        system("cls");                                                     // clear screen
        displayHUD(player, day, quota[day - 1]);                           // display HUD
        maze.displayRoom(player.getRow(), player.getCol());                // display current room
        std::cout << "Move (W/A/S/D) or Q to exit the maze for the day: "; // prompt user for input
        char input = getCharChoice("WASDQ");                               // get and validate player input

        if (input == 'Q') // if user inputs q
        {
            std::cout << "\nLeaving the maze...\n"; // tell them they're leaving
            if (player.getMoney() >= quota[day - 1])      // if they've met their quota
            {
                displayDayComplete(day); // display day complete message

                player.addMoney(-quota[day - 1]); // Sketch Malone takes his cut (subtracts quota from total)
                day++;                            // increment day counter

                if (day > 3) // if they've completed all days
                {
                    displayGameWon(); // display game won message
                    return 0;
                }
                
                player.resetHearts();                  // reset hearts
                maze.generateMaze();                   // generate new maze
                player.setPosition(2, 2);              // recenter player
                continue;
            }
            else
            {
                displayGameOver(); // display game over message
                return 0;
            }
        }
        /*movement*/
        int r = player.getRow();            // row coordinate from player object
        int c = player.getCol();            // column coordinate from player object
        Room &current = maze.getRoom(r, c); // get room at current location

        bool canMove =
            (input == 'W' && current.isOpenTop()) ||
            (input == 'S' && current.isOpenBottom()) ||
            (input == 'A' && current.isOpenLeft()) ||
            (input == 'D' && current.isOpenRight()); // check if player can move in desired direction

        if (!canMove) // if player cannot move in desired direction
        {
            std::cout << "\nYou bump into a wall.\n"; // error message
            waitForKey();                             // wait for key press before continuing
            continue;
        }

        int newR = r; // row coordinate for new location
        int newC = c; // column coordinate for new location

        if (input == 'W') // if player wants to move north
            newR--;       // decrement row by one
        if (input == 'S') // if player wants to move south
            newR++;       // increment row by one
        if (input == 'A') // if player wants to move west
            newC--;       // decrement column by one
        if (input == 'D') // if player wants to move east
            newC++;       // increment column by one

        // animate walking
        char dir = (input == 'W' ? 'U' : (input == 'S' ? 'D' : (input == 'A' ? 'L' : 'R'))); // convert W,A,S,D to U,L,D,R
        animatePlayerWalk(dir);                                                              // animate walking function
        player.setPosition(newR, newC);                                                      // update player position

        system("cls");                           // clear screen
        displayHUD(player, day, quota[day - 1]); // display HUD
        maze.displayRoom(newR, newC);            // display new room

        Room &newRoom = maze.getRoom(newR, newC); // get room at new location
        newRoom.setVisited(true);                 // mark room as visited

        /*items*/
        if (newRoom.getItem() && !newRoom.getItem()->isCollected())
        {                                      // if new room contains an item and it hasn't been collected yet
            Item *item = newRoom.getItem();    // get item from room using pointer
            displayItemPickup(*item);          // display pickup message for the item
            player.addMoney(item->getValue()); // add item value to player's money
            item->setCollected(true);          // mark item as collected
        }
        /*monsters*/
        if (newRoom.getMonster() && !newRoom.getMonster()->isDefeated())
        {                                                          // if new room contains a monster and it hasn't been defeated yet
            Monster *m = newRoom.getMonster();                     // get monster from room using pointer
            displayMonsterEncounter(m->getName(), m->getDesc());   // display encounter message for the monster
            std::string name = m->getName();                       // get monster name using pointer
            bool win = false;                                      // boolean variable for player winning
            int diff = m->getDifficulty();                         // get monster difficulty using pointer
            if (diff == 1)                                         // if monster is common
                win = (rand() % 2 ? vending(name) : dodge(name));  // randomly choose between two common minigames
            else if (diff == 2)                                    // if monster is uncommon
                win = (rand() % 2 ? code(name) : company(name));   // randomly choose between two uncommon minigames
            else                                                   // if monster is rare
                win = (rand() % 2 ? memorize(name) : shake(name)); // randomly choose between two rare minigames

            if (win) // if player wins
            {
                m->setDefeated(true);         // mark monster as defeated
                newRoom.setMonster(nullptr);  // remove monster from room
                displayMonsterDefeated(name); // display defeat message for the monster
            }
            else // if player loses
            {
                player.loseHeart();                          // lose a heart
                displayMonsterHit(name, player.getHearts()); // display hit message for the monster
                if (player.getHearts() <= 0)                 // if player runs out of hearts
                {
                    displayGameOver(); // display game over message
                    return 0;
                }
            }
        }
       
    }
    return 0;
}
