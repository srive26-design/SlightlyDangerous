// item.h - header file for the Item class
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{ // Item class declaration
private:
    std::string name; // name of the item
    int value;        // how many credits the item is worth
    bool collected;   // true after the player picks it up
    std::string lore; // lore/description of the item
public:
    Item(std::string n, int v, std::string l = ""); // contructor for item object
    std::string getName() const { return name; }    // get the name of the item
    int getValue() const { return value; }          // get the value of the item
    std::string getLore() const { return lore; }    // get the lore of the item
    bool isCollected() const { return collected; }  // check if the item has been picked up
    void setCollected(bool c) { collected = c; }    // set the item as collected
};

struct ItemInfo
{                     // struct to hold item information
    std::string name; // name of the item
    int minValue;     // minimum possible value
    int maxValue;     // maximum possivle value
    std::string lore; // description
};

// extern b/c defined in item.cpp and doesn't need to be redefined everywhere
// const b/c should not be edited anywhere else
extern const ItemInfo COMMON[];   // array of items with common rarity
extern const int COMMON_COUNT;    // number of items in COMMON array
extern const ItemInfo UNCOMMON[]; // array of items with uncommon rarity
extern const int UNCOMMON_COUNT;  // number of items in UNCOMMON array
extern const ItemInfo RARE[];     // array of items with rare rarity
extern const int RARE_COUNT;      // number of items in RARE array

#endif