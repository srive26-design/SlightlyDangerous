// monster.h - header file for the Monster class
#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{ // monster class declaration
private:
    std::string name; // name of the monster
    std::string desc; // description of the monster
    int difficulty;   // difficulty level of the monster
    bool defeated;    // whether the monster has been defeated
public:
    Monster();                                                      // default constructor
    Monster(std::string monsterName, int diff, std::string d = ""); // takes in a string and an integer as parameters

    // getters to get private member variables
    std::string getName() const { return name; } // gives read only access to the name variable
    std::string getDesc() const { return desc; } // can't modify it b/c const
    int getDifficulty() const { return difficulty; }
    bool isDefeated() const { return defeated; }

    void setDefeated(bool d) { defeated = d; } // setter function to change value of defeated variable
};

struct MonsterInfo /// struct that holds info about monsters
{
    std::string name; // name of monster
    int baseDifficulty; // base difficulty of monster
    std::string description; // description of monster
};

// arrays of structs containing information about each type of monster
extern const MonsterInfo COMMON_M[]; // extern b/c arrays defined in monster.cpp not here
extern const int COMMON_MCOUNT; // const b/c we don't want to be able to change them

extern const MonsterInfo UNCOMMON_M[];
extern const int UNCOMMON_MCOUNT;

extern const MonsterInfo RARE_M[];
extern const int RARE_MCOUNT;

#endif