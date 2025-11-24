// item.cpp - implementation file for the Item class

#include "item.h" // include header file

/* Constructor for Item object */
Item::Item(std::string n, int v, std::string l)
{
    name = n;          // assign item name
    value = v;         // assign item value
    lore = l;          // assign item description
    collected = false; // item starts as not collected
}

// Common items - name, min and max values, and descriptions
const ItemInfo COMMON[] =
    {
        {"Rusty Bolt", 5, 10, "Must\'ve fell off of a machine long abandoned"}, // backslash needed because apostrophe
        {"Landline Phone", 15, 25, "How old is this thing??"},                  // first number is min value, second is max value
        {"Dirty Keyring", 5, 15, "Several keys, none labeled."},                // first string is name, last string is description
        {"Worn Screwdriver", 10, 20, "The grip is cracked from use."},
        {"Scrap Metal", 15, 20, "Don\'t get tetanus, the edges are sharp."},
        {"Broken Watch", 30, 45, "The hands move backwards.. suspicious."},
        {"Faded Photograph", 15, 30, "A picture of a family, faces obscured."},
        {"Old Comic Book", 5, 10, "Pages yellowed with age."},
        {"Chemistry Flask", 5, 10, "Smells kinda acidic."}};
const int COMMON_COUNT = 9; // 9 items in common array

// Uncommon items - name, min and max values, and descriptions
const ItemInfo UNCOMMON[] =
    {
        {"Ancient Relic", 40, 80, "Symbols you don\'t recognize."},
        {"Sketch\'s Lost Wallet", 40, 100, "Do you have to return this?"},
        {"Overloaded Battery Pack", 35, 75, "You can hear the battery hum through it\'s case"},
        {"Case of Bottles", 30, 60, "WHO drank ALL that?"},
        {"Chemical Jug", 25, 90, "Don\'t inhale the fumes."}};
const int UNCOMMON_COUNT = 5; // 5 items in uncommon array

// Rare items - name, min and max values, and descriptions
const ItemInfo RARE[] =
    {
        {"Magic 7 Ball", 150, 350, "Shake it, ask a question."},
        {"Apparatus", 100, 300, "Why is it still on after being disconnected?"},
        {"V-type Engine", 170, 360, "Motor oil drips from its core."},
        {"Holographic Projector", 180, 380, "Projects glitched company training videos from time to time."},
        {"Decommissioned Robot", 220, 400, "Still loops old corporate slogans through it\'s voice unit"}};
const int RARE_COUNT = 5; // 5 items in rare array
