// utils.cpp - implementation file for utility functions
#include "utils.h"

#include <cctype>   // toupper
#include <iostream> // cin/cout
#include <thread>   // this_thread
#include <chrono>   // sleep_for

void waitForKey()
{
    std::cout << "\nPress Enter to continue..."; // prompt user
    while (std::cin.peek() != '\n' && std::cin.peek() != EOF)
    { // flush any leftover input first
        std::cin.get();
    }
    std::cin.get(); // wait for enter key
}

void delay(int ms) // delay helper for timing
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms)); // delay in milliseconds
}

int getIntInRange(int min, int max) // gets an integer from the user within a range of values
{
    int value;   // variable to store user's input
    while (true) // loop until a valid input is received
    {
        std::cin >> value; // read input from user

        if (!std::cin.fail() && value >= min && value <= max) // if input is valid and within range
        {
            while (std::cin.peek() != '\n' && std::cin.peek() != EOF) // while there are characters left in the input stream
                std::cin.get();                                       // consume remaining characters
            std::cin.get();                                           // consume newline
            return value;                                             // return the valid input
        }

        std::cin.clear(); // reset input state
        while (std::cin.peek() != '\n' && std::cin.peek() != EOF)
            std::cin.get(); // clear junk from buffer
        std::cin.get();     // consume newline
        std::cout << "Invalid choice. Try again (" << min << "-" << max << "): ";
    }
}

char getCharChoice(const std::string &validOptions)
{                // get single character input from allowed options
    char c;      // variable to store user's input
    while (true) // loop until a valid input is received
    {
        std::cin >> c;                                            // read input from user
        c = toupper(c);                                           // convert to uppercase
        while (std::cin.peek() != '\n' && std::cin.peek() != EOF) // while there are characters left in the input stream
            std::cin.get();                                       // consume remaining characters
        std::cin.get();                                           // consume newline
        if (validOptions.find(c) != std::string::npos)            // if option exists in string
            return c;                                             // return it

        std::cout << "Invalid input. Valid options: " << validOptions << "\nTry again: "; // otherwise print error message
    }
}