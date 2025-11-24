// hud.h - screen display functions
#ifndef HUD_H
#define HUD_H

#include "player.h" // for player class
#include "item.h"   // for item class
#include "utils.h"  // for waitForKey function
#include <string>

void displayHUD(const Player &player, int day, int quota);                      // display main game HUD w/ player stats and quota
void displayItemPickup(const Item &item);                                       // display message when item is picked up
void displayMonsterEncounter(const std::string &name, const std::string &desc); // display message when monster is encountered
void displayDayComplete(int day);                                               // end of the day summary message
void displayGameWon();                                                          // winning message
void displayGameOver();                                                         // losing message
void displayMonsterDefeated(const std::string &name);                           // display message when monster is defeated
void displayMonsterHit(const std::string &name, int heartsLeft);                // display message when player loses to monster
int displayMenu();                                                              // menu display
void displayRules();                                                            // rules display
#endif
