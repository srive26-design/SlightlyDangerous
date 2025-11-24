// minigames.h - declarations for all monster minigames
#ifndef MINIGAMES_H
#define MINIGAMES_H

#include "monster.h"
#include "utils.h" // for input validation functions
#include <string>

/*common monster games*/
bool vending(const std::string& monsterName); 
bool dodge(const std::string& monsterName);
/*uncommon monster games*/
bool code(const std::string& monsterName);
bool company(const std::string& monsterName);
/*rare monster games*/
bool memorize(const std::string& monsterName);
bool shake(const std::string& monsterName);
//bool functions so win = true, lose = false

void showCountdown(int seconds); //countdown timer function

#endif
