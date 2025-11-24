// monster.cpp - implementation file for the Monster class

#include "monster.h"
#include <string>

// default monster
Monster::Monster()
{
    name = "Unknown"; // default values
    desc = "";
    difficulty = 1;
    defeated = false;
}

// parameterized monster
Monster::Monster(std::string monsterName, int diff, std::string d)
{
    name = monsterName; // set name
    difficulty = diff;  // set difficulty
    desc = d;           // set description
    defeated = false;   // monster always starts out not being defeated
}
// common monster list
const MonsterInfo COMMON_M[] = {
    {"A Club Bouncer", 1, "He snapped your ID."},
    {"The Green Goblin", 1, "Green, tiny, and smug."},
    {"A Lost Janitor", 1, "Doesn\'t remember how he got here."},
    {"An NYC Rat", 1, "OH GOD IT\'S HUGE"}};
const int COMMON_MCOUNT = 4;

// uncommon monster list
const MonsterInfo UNCOMMON_M[] = {
    {"The Shadow Lurker", 2, "Flickers like bad fluorescent lighting."},
    {"The Mad Mechanic", 2, "Carries tools you\'ve never seen before."},
    {"The Hollow Ghoul", 2, "You can see through parts of its body."}};
const int UNCOMMON_MCOUNT = 3;

// rare monster list
const MonsterInfo RARE_M[] = {
    {"The Maze Warden", 3, "Its footsteps shake the floor."},
    {"The Skin Walker", 3, "Something is wrong with it."},
    {"Sketch\'s Dad", 3, "Seems aware of your debt."}};
const int RARE_MCOUNT = 3;
