// utils.h - utility functions and classes used by multiple files
#ifndef UTILS_H
#define UTILS_H

#include <string>

void waitForKey(); // waits for a key press before continuing
void delay(int ms); // delays execution of program for specified number of milliseconds
int getIntInRange(int min, int max); // gets an integer from the user within a range
char getCharChoice(const std::string& validOptions); // gets a character choice from the user
#endif
