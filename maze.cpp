// maze.cpp - implementation of the maze class
#include "maze.h"
#include "monster.h"
#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <algorithm> // for swap()

extern int day; // global day used for difficulty scaling during spawns

Maze::Maze(int r, int c) // maze constructor
{
    rows = r; // store dimensions
    cols = c;
    grid.resize(rows, std::vector<Room>(cols));    // build rows x columns of default rooms
    std::srand(static_cast<unsigned>(time(NULL))); // seed random number generator
}

Item *Maze::generateRandomItem() // random item generation
{
    int roll = std::rand() % 100; // variable to store random number, 0-99, to determine item rarity

    const ItemInfo *pool = nullptr; // pointer to either common, uncommon or rare item array
    int poolSize = 0;               // size of that array

    if (roll < 70) // if the random number is less than 70
    {
        pool = COMMON;           // the item is common
        poolSize = COMMON_COUNT; // size of the common item array
    }
    else if (roll < 90) // if the random number is greater than 70 but less than 90
    {
        pool = UNCOMMON;           // the item is uncommon
        poolSize = UNCOMMON_COUNT; // size of the uncommon item array
    }
    else // if the random number is greater than 90
    {
        pool = RARE;           // the item is rare
        poolSize = RARE_COUNT; // size of the rare item array
    }

    const ItemInfo &chosen = pool[std::rand() % poolSize]; // the item info chosen is random based on rarity array

    int basevalue = chosen.minValue + (std::rand() % (chosen.maxValue - chosen.minValue + 1)); // basevalue of item is random within min/max range
    int value = basevalue + (day * 5);                                                         // value of item is increased by 5% per day
    return new Item(chosen.name, value, chosen.lore);                                          // create new item with chosen info and return its address
}

Monster *Maze::generateRandomMonster(int day) // random monster generation
{
    const MonsterInfo *pool = nullptr;               // pointer to either common, uncommon or rare monster array
    int poolSize = 0;                                // size of that array
    int roll = std::rand() % 100;                    // variable to store random number, 0-99, to determine monster rarity
    int commonLimit = 60 - (day * 20);               // limit for common monsters decreases by 20% per day
    int uncommonLimit = commonLimit + 15 + day * 15; // limit for uncommon monsters is 15% greater than common limit and increases by 5% per day

    if (roll < commonLimit) // if the random number is less than commonLimit
    {
        pool = COMMON_M;          // the monster is common
        poolSize = COMMON_MCOUNT; // size of the common monster array
    }
    else if (roll < uncommonLimit) // if the random number is less than uncommonLimit but greater than commonLimit
    {
        pool = UNCOMMON_M;          // the monster is uncommon
        poolSize = UNCOMMON_MCOUNT; // size of the uncommon monster array
    }
    else // if the random number is greater than uncommonLimit
    {
        pool = RARE_M;          // the monster is rare
        poolSize = RARE_MCOUNT; // size of the rare monster array
    }

    const MonsterInfo &m = pool[std::rand() % poolSize]; // the monster info chosen is random based on rarity array
    int diff = m.baseDifficulty + (day - 1);             // difficulty scales linearly with day
    if (diff < 1)                                        // if difficulty drops below 1 (min = 1)
        diff = 1;                                        // difficulty will be set to 1
    if (diff > 3)                                        // if difficulty exceeds 3 (max = 3)
        diff = 3;                                        // difficulty will be set to 3

    return new Monster(m.name, diff, m.description); // create new monster with chosen info and return its address
}

Room &Maze::getRoom(int r, int c) // returns a reference to the room at position (r,c)
{
    return grid[r][c]; // return reference so changes affect the actual room in the maze, not a copy
}

void Maze::generateMaze() // resets all rooms, carves a new maze, then adds items and monsters
{
    // 1) reset all rooms - walls closed, unvisited, no items/monsters
    for (int r = 0; r < rows; r++) // for each row
    {
        for (int c = 0; c < cols; c++) // for each column
        {
            Room &room = grid[r][c];   // get reference to room at position (r,c)
            room.setOpenTop(false);    // close top wall
            room.setOpenBottom(false); // close bottom wall
            room.setOpenLeft(false);   // close left wall
            room.setOpenRight(false);  // close right wall
            room.setVisited(false);    // mark as unvisited

            if (room.getItem())        // if there's already an item here
                delete room.getItem(); // delete it
            room.setItem(nullptr);     // remove any existing item

            if (room.getMonster())        // if there's already a monster here
                delete room.getMonster(); // delete it
            room.setMonster(nullptr);     // remove any existing monster
        }
    }

    // 2) start from a random room and carve the maze
    int startR = std::rand() % rows; // random starting row/column
    int startC = std::rand() % cols;

    generateRecursive(startR, startC); // function call to carve the maze from random starting point

    // 3.) randomly add items and monsters
    for (int r = 0; r < rows; r++) // for each row
    {
        for (int c = 0; c < cols; c++) // for each column
        {
            Room &room = grid[r][c]; // get reference to room at position (r,c)

            int itemSpawnChance = 25 + (day * 20); // chance of spawning an item increases by 20% per day
            if (itemSpawnChance > 80)              // if spawn chance goes over 80
                itemSpawnChance = 80;              // set to 80

            if (room.getItem() == nullptr && (std::rand() % 100) < itemSpawnChance)
            {                                       // if there isn't an item here yet and the random number is less than the spawn chance
                room.setItem(generateRandomItem()); // place a random item in this room
            }

            int monsterSpawnChance = 30 + (day * 15); // chance of spawning a monster increases by 15% per day
            if (monsterSpawnChance > 85)              // if spawn chance goes over 85
                monsterSpawnChance = 85;              // set to 85
            if (room.getMonster() == nullptr && (std::rand() % 100) < monsterSpawnChance)
            {                                                // if there isn't a monster here yet and the random number is less than the spawn chance
                room.setMonster(generateRandomMonster(day)); // place a random monster in this room
            }
        }
    }
}

void Maze::generateRecursive(int r, int c) // recursive backtracking maze generation
{
    grid[r][c].setVisited(true); // mark current room as visited

    int directions[4] = {0, 1, 2, 3}; // 0 = top, 1 = bottom, 2 = left, 3 = right
    for (int i = 0; i < 4; i++)       // for each possible direction
    {
        int j = std::rand() % 4;                 // pick a random direction
        std::swap(directions[i], directions[j]); // swap to randomize order
    }

    for (int i = 0; i < 4; i++) // for each direction
    {
        int dir = directions[i]; // direction is from randomized list above
        int newR = r;            // start at current room
        int newC = c;

        if (dir == 0 && r > 0)             // if in bounds
            newR--;                        // move up one row
        else if (dir == 1 && r < rows - 1) // if in bounds
            newR++;                        // move down one row
        else if (dir == 2 && c > 0)
            newC--; // move left one column
        else if (dir == 3 && c < cols - 1)
            newC++; // move right one column
        else
            continue; // skip out-of-bounds moves

        if (!grid[newR][newC].isVisited()) // if the next room hasn't been visited
        {
            if (dir == 0) // opening between current and top
            {
                grid[r][c].setOpenTop(true);
                grid[newR][newC].setOpenBottom(true);
            }
            else if (dir == 1) // opening between current and bottom
            {
                grid[r][c].setOpenBottom(true);
                grid[newR][newC].setOpenTop(true);
            }
            else if (dir == 2) // opening between current and left
            {
                grid[r][c].setOpenLeft(true);
                grid[newR][newC].setOpenRight(true);
            }
            else if (dir == 3) // opening between current and right
            {
                grid[r][c].setOpenRight(true);
                grid[newR][newC].setOpenLeft(true);
            }

            generateRecursive(newR, newC); // recurse into the neighbor room
        }
    }
}

void Maze::displayRoom(int r, int c) const // prints a single room at (r,c), including player, items, and monsters
{
    const Room &current = grid[r][c]; // get constant reference to room at position (r,c)

    const int H = 11; // height of room
    const int W = 21; // width of room

    for (int i = 0; i < H; i++) // for each row
    {
        for (int j = 0; j < W; j++) // for each column
        {

            if (i == H / 2 && j == W / 2) // if we're printing the center row/column
            {
                std::cout << "P"; // print P for player, the player is always centered
            }

            // if top is open, carve through walls to display opening in top direction
            else if (i == 0 && current.isOpenTop() && j >= W / 2 - 1 && j <= W / 2 + 1)
                std::cout << " ";

            // if bottom is open, carve through walls to display opening in bottom direction
            else if (i == H - 1 && current.isOpenBottom() && j >= W / 2 - 1 && j <= W / 2 + 1)
                std::cout << " ";

            // if left is open, carve through walls to display opening in left direction
            else if (j == 0 && current.isOpenLeft() && i >= H / 2 - 1 && i <= H / 2 + 1)
                std::cout << " ";

            // if right is open, carve through walls to display opening in right direction
            else if (j == W - 1 && current.isOpenRight() && i >= H / 2 - 1 && i <= H / 2 + 1)
                std::cout << " ";

            // besides openings and middle row/column, fill with walls
            else if (i == 0 || i == H - 1) // top and bottom walls
                std::cout << "#";
            else if (j == 0 || j == W - 1) // left and right walls
                std::cout << "=";

            // display items above the center in the room
            else if (current.getItem() && !current.getItem()->isCollected() && i == H / 2 - 2 && j == W / 2)
                std::cout << "$"; // symbol for item, maybe replace with ascii art later

            // display monsters below the center in the room
            else if (current.getMonster() && !current.getMonster()->isDefeated() && i == H / 2 - 2 && j == W / 2)
                std::cout << "M"; // symbol for monster, maybe replace with ascii art later

            else
                std::cout << " "; // empty space inside room
        }
        std::cout << "\n";
    }
}
