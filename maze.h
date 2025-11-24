// maze.h - header file for the Maze class
#ifndef MAZE_H
#define MAZE_H
#include "room.h"
#include "item.h"
#include "monster.h"
#include <vector>
#include <string> // forstd::string in renderRoomBuffer

class Maze
{ // maze class declaration
private:
    int rows;                            // number of rows in the maze
    int cols;                            // number of columns in the maze
    std::vector<std::vector<Room>> grid; // 2D grid storing all rooms in the maze

    // helper function for maze generation
    void generateRecursive(int r, int c); // uses recursive backtracking to carve a perfect maze with no isolated sections

public:
    Maze(int r = 5, int c = 5); // Constructor with default size 5x5

    // getters
    int getRows() const; // returns number of rows
    int getCols() const; // returns number of columns

    Room &getRoom(int r, int c);          // returns a reference so changes affect the actual room in the maze, not a copy
    void displayBasic() const;            // displays basic layout of the maze
    void generateMaze();                  // generates a new maze using recursive backtracking algorithm
    void displayRoom(int r, int c) const; // displays a single room at (r, c)
    Item *generateRandomItem();           // generates a random item
    Monster *generateRandomMonster(int day);     // generates a random item
};
#endif