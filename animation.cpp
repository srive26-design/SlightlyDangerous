// animation.cpp - implementation of hallway walking "animation"
#include "animation.h"
#include <iostream>
#include <vector> // for vector
#include <string>
#include <algorithm> // for max(), min()
#include <thread>    // for thread
#include <chrono>    // for sleep_for()
#include <cstdlib>   // for system()

// displays player walking along a hallway
void animatePlayerWalk(char dir)
{
    const int steps = 12;   // number of animation frames
    const int delayMs = 40; // milliseconds to wait between frames

    int row = 5;  // starts P in middle of row (P represents player)
    int col = 14; // starts P in middle of column

    // Vertical hallway display
    std::vector<std::string> vert = {
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:",
        "    :|        |:"};

    // Horizontal hallway display
    std::vector<std::string> horz = {
        "============================",
        "                            ",
        "                            ",
        "============================"};

    for (int i = 0; i < steps; i++) // for each animation frame
    {
        system("cls"); // clear screen

        // Update position
        if (dir == 'L')
            col--; // if direction is left, decrement column, shows as moving left
        if (dir == 'R')
            col++; // if dir is right increment column, shows as moving right
        if (dir == 'U')
            row--; // if dir up decrement row, shows as moving up
        if (dir == 'D')
            row++; // if dir down increment row, shows as moving down

        // Keep in bounds of screen
        col = std::max(1, std::min(col, 27)); // min(col, 27) means if col > 27 it will be set to 27, and max(col, 1) means if col < 1 it will be set to 1. This keeps the player on the screen.
        row = std::max(1, std::min(row, 8));  // if row > 8 it will be set to 8, and min(row, 1) means if row < 1 it will be set to 1.

        if (dir == 'U' || dir == 'D') // if the direction is up or down, then we use the vertical hallway display
        {
            // Reset vertical hallway
            for (auto &line : vert) // for each string in vert and allow modifying it directly
                line = "    :|        |:";

            // Put player in center column
            if (row >= 0 && row < (int)vert.size() && 10 >= 0 && 10 < (int)vert[row].size()) // if row is within range of vert and col is within range of vert[row]
                vert[row][10] = 'P';                                                         // then set vert[row][col] to 'P'. This puts the player in the center column.

            for (auto &line : vert)        // for each line in vert
                std::cout << line << "\n"; // print out the line
        }
        else // otherwise, we use the horizontal hallway display
        {
            // Reset horizontal hallway
            horz[0] = "============================"; // is shorter than vert so no need for loop here
            horz[3] = "============================";
            horz[1] = "                            ";
            horz[2] = "                            ";

            if (2 >= 0 && 2 < (int)horz.size() && col >= 0 && col < (int)horz[2].size()) // if col is within range of horz[2]
                horz[2][col] = 'P';                                                      // then put the player at that location

            for (auto &line : horz)        // for each line in horz
                std::cout << line << "\n"; // print out the line
        }
        delay(delayMs); // pause animation for 40 milliseconds
    }
}
