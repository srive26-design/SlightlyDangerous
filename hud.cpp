// hud.cpp - implementation of display related screen popups/ HUD visuals
#include "hud.h"
#include <iostream> // cout, cin

// display game HUD, shows current day, money, hearts and the daily quota
void displayHUD(const Player &player, int day, int quota)
{ // needs the player class for hearts and money
    std::cout << "=====================================\n";
    std::cout << "   Slightly Dangerous LLC (v1.0)\n";
    std::cout << "-------------------------------------\n";
    std::cout << " Day: " << day
              << " | Money: $" << player.getMoney()  // call getMoney method in player class
              << " | Hearts: " << player.getHearts() // call getHearts method in player class
              << " | Quota: $" << quota << "\n";
    std::cout << "=====================================\n\n";
}
// display fullscreen item pickup message, shows item name, value and lore
void displayItemPickup(const Item &item)
{
    system("cls"); // clear console screen

    std::string name = item.getName(); // name from item object
    int value = item.getValue();       // value from item object
    std::string lore = item.getLore(); // lore from item object

    std::cout << "=====================================\n";
    std::cout << "         ITEM ACQUIRED!\n";
    std::cout << "=====================================\n\n";
    std::cout << " >> " << name << " <<\n\n"; // item name
    std::cout << "Value: $" << value << "\n"; // item value

    if (!lore.empty()) // if there is lore
    {
        std::cout << "\n"
                  << lore << "\n"; // print lore
    }
    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Continue...";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display fullscreen monster encounter message, shows monster name and description
void displayMonsterEncounter(const std::string &name, const std::string &desc)
{
    system("cls"); // clear console screen

    std::cout << "=====================================\n";
    std::cout << "        MONSTER ENCOUNTER!\n";
    std::cout << "=====================================\n\n";

    std::cout << ">> " << name << " <<\n\n"; // monster name
    std::cout << desc << "\n";               // monster description
    std::cout << "\nPrepare for a minigame...\n";

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Once Ready...";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display after a day ends, shows day number
void displayDayComplete(int day)
{
    system("cls"); // clear console screen

    std::cout << "=====================================\n";
    std::cout << "           DAY " << day << " COMPLETE\n";
    std::cout << "=====================================\n\n";

    std::cout << "Sketch Malone watches you leave...\n"; // maybe change words per day?
    std::cout << "\"You survived... for now.\"\n";

    std::cout << "\nRest while you can.\n";

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Head on to the Next Day";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display when the player escapes, shows final message
void displayGameWon()
{
    system("cls"); // clear console screen

    std::cout << "=====================================\n";
    std::cout << "            YOU ESCAPED\n";
    std::cout << "=====================================\n\n";

    std::cout << "Your debt is paid.\n";
    std::cout << "Sketch leaves you with a business card\n\n";
    std::cout << "Freedom feels... unfamiliar.\n";

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Rejoice in Your Freedom!";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display when the player dies, shows final message
void displayGameOver()
{
    system("cls");

    std::cout << "=====================================\n";
    std::cout << "             GAME OVER\n";
    std::cout << "=====================================\n\n";

    std::cout << "Sketch Malone sighs.\n";
    std::cout << "\"Another one lost to the maze.\"\n";

    std::cout << "\nYour journey ends here.\n";

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Face Sketch...";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display fullscreen monster defeated message, shows monster name
void displayMonsterDefeated(const std::string &name)
{
    system("cls"); // clear console screen
    std::cout << "=====================================\n";
    std::cout << "         MONSTER DEFEATED\n";
    std::cout << "=====================================\n\n";

    std::cout << "You outplayed the " << name << ".\n"; // randomize this message
    std::cout << "It retreats into the maze...\n";      // randomize this message

    std::cout << "\nYou feel a strange sense of relief.\n"; // randomize this message

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Continue...";
    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display lost to monster message, show monster name and number of hearts left
void displayMonsterHit(const std::string &name, int heartsLeft)
{
    system("cls"); // clear console screen
    std::cout << "=====================================\n";
    std::cout << "          YOU WERE HIT\n";
    std::cout << "=====================================\n\n";

    std::cout << "The " << name << " strikes you!\n"; // show monster name
    std::cout << "You lose 1 heart.\n\n";             // player loses a heart

    std::cout << "Hearts remaining: " << heartsLeft << "\n"; // show how many hearts are left

    std::cout << "\n=====================================\n";
    std::cout << "Press Enter to Continue...";

    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
// display main menu
int displayMenu()
{
    while (true) // loop until valid input is given
    {
        system("cls"); // clear console screen
        std::cout << "========================================\n";
        std::cout << "        Slightly Dangerous LLC\n";
        std::cout << "========================================\n";
        std::cout << "      Accidents happen. Usually.\n";
        std::cout << "----------------------------------------\n";
        std::cout << "           [1] New Game\n";
        std::cout << "           [2] How to Play\n";
        std::cout << "           [3] Quit\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Enter your choice: ";

        char choice = getCharChoice("123"); // get user input and validate it using helper function

        if (choice == '1') // if user enters 1
        {
            return 1; // start the game
        }
        else if (choice == '2') // if user enters 2
        {
            displayRules(); // display rules
            continue;       // redisplay menu
        }
        else if (choice == '3') // if user enters 3
        {
            return 0;
        }
    }
}
// display game instructions
void displayRules()
{
    system("cls"); // clear console screen
    std::cout << "              HOW TO PLAY\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Use W, A, S, D to move between rooms.\n";
    std::cout << "Each room may contain an item or a monster.\n";
    std::cout << "Collect items to earn money.\n";
    std::cout << "Defeat monsters by completing minigames.\n";
    std::cout << "Losing a minigame means you lose a heart\n";
    std::cout << "Lose all hearts = game over.\n";
    std::cout << "Press 'Q' to leave the maze for the day\n";
    std::cout << "Meet your daily quota to survive.\n";
    std::cout << "----------------------------------------\n";
    std::cout << "\nPress Enter to Return to Menu...";
    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
}
