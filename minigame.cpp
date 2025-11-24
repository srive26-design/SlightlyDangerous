// minigame.cpp - minigame functions
#include <iostream>
#include <cstdlib> // for srand(), rand()
#include <chrono>  // for steady_clock::now(), duration_cast<>()
#include <thread>  // for this_thread::sleep_for()
#include <cctype>  // for toupper()

#include "minigame.h"

void showCountdown(int seconds) // function to display timer
{
    for (int i = seconds; i > 0; i--) // for loop that counts down from given number of seconds
    {
        std::cout << "\rTime left: " << i << " seconds " << std::flush; // displays countdown, /r to overwrite previous line instead of printing new line
        std::this_thread::sleep_for(std::chrono::seconds(1));           // pauses program for one second
    }
    std::cout << "\rTime\'s up!            \n"; // after counting down, prints time's up w/ spaces to clear out old text
}

bool vending(const std::string &monsterName)
{
    system("cls");                                                         // clears screen
    std::cout << "A malfunctioning vending machine flickers violently.\n"; // game intro/instructions
    std::cout << monsterName << " stands guard beside it, watching your every move.\n";
    std::cout << "\"Choose correctly,\" it warns.\n\n";

    int correct = rand() % 3 + 1; // variable to store random correct choice between 1 and 3
    int choice;                   // variable to store user's choice

    std::cout << "Three buttons light up:\n"; // prints three choices
    std::cout << "1) Cracked Energy Drink\n";
    std::cout << "2) Unlabeled Can\n";
    std::cout << "3) Expired Iced Tea\n\n";

    std::cout << "Which do you press? (1-3): ";
    choice = getIntInRange(1, 3); // gets input from user and checks if it's valid
    return (choice == correct);   // if user's choice matches correct choice, returns true, otherwise returns false
}

bool dodge(const std::string &monsterName)
{
    system("cls");                                                 // clears screen
    std::cout << monsterName << " suddenly charges toward you!\n"; // game intro
    std::cout << "You have only a split second to dodge.\n\n";

    char directions[3] = {'L', 'C', 'R'}; // char array of possible directions
    char attackDir;                       // variable to store the winning random direction
    attackDir = directions[rand() % 3];   // assign random direction to attackDir

    std::cout << "DODGE NOW!\n"; // prints instructions
    std::cout << "Choose a direction:\n";
    std::cout << "  (L)eft\n";
    std::cout << "  (C)enter\n";
    std::cout << "  (R)ight\n\n";

    std::cout << "Your move: ";

    char choice = getCharChoice("LCR"); // gets input from user and checks if it's valid

    return choice == attackDir; // if user's choice matches attack direction, returns true, otherwise returns false
}
bool code(const std::string &monsterName)
{
    system("cls");
    std::cout << monsterName << " blocks a locked terminal of the maze.\n"; // game intro
    std::cout << "\"ENTER VERIFICATION CODE TO PROCEED.\"\n\n";

    std::string code = "CBHJ" + std::to_string(rand() % 900 + 100); // generate string with randomly generated last three digits as code
    std::cout << "TYPE THIS CODE EXACTLY:  " << code << "\n";       // game instructions
    std::cout << "You have 10 seconds.\n\n";
    // use thread to run countdown function since countdown should run while main program waits for user input
    std::thread timer(showCountdown, 10);
    std::string input;                             // string to hold user input
    auto start = std::chrono::steady_clock::now(); // start timer
    std::cin >> input;                             // get user input
    auto end = std::chrono::steady_clock::now();   // end timer

    timer.join(); // stop countdown once input finishes
    // calculate total time taken
    long long elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cin.clear(); // clear input buffer
    while (std::cin.get() != '\n')
    {
    }
    if (elapsed > 10) // if more than 10 seconds passed
        return false; // return false = player lost

    return input == code; // else check if user input equals code, if yes then return true = player won
}

bool company(const std::string &monsterName)
{
    system("cls");
    std::cout << monsterName << " drifts silently in front of you.\n"; // game intro
    std::cout << "\"Answer correctly to proceed.\"\n\n";

    std::cout << "What is the most professional response?\n"; // game questions
    std::cout << "A) Ignore the issue entirely\n";
    std::cout << "B) Address it calmly and responsibly\n";
    std::cout << "C) Scream louder than everyone else\n\n";
    std::cout << "Your answer: ";

    char choices[3] = {'A', 'B', 'C'};  // array of possible answers
    char correct = choices[rand() % 3]; // randomly select correct answer
    char choice = getCharChoice("ABC"); // gets input from user and checks if it's valid

    return choice == correct; // if user's choice matches correct answer, returns true, otherwise returns false
}

bool memorize(const std::string &monsterName)
{
    system("cls");
    std::cout << "The corridor distorts around " << monsterName << ".\n";          // game intro
    std::cout << "Memorize the sequence before it fades. You have 3 seconds.\n\n"; // game instructions

    char symbols[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'Z', 'Y', 'X', 'W'}; // array of possible symbols in sequence
    std::string seq;                                                       // string to hold sequence

    for (int i = 0; i < 6; i++)      // for a loop of six iterations
        seq += symbols[rand() % 10]; // add random symbol from array to sequence

    std::cout << "SEQUENCE: " << seq << "\n"; // print sequence
    std::cout << "Get ready...\n";

    std::this_thread::sleep_for(std::chrono::seconds(3)); // wait 3 seconds

    system("cls"); // clear screen again

    std::string input;                   // string to hold user input
    std::cout << "Enter the sequence: "; // print prompt
    std::cin >> input;                   // get user input

    std::cin.clear(); // clear input buffer
    while (std::cin.get() != '\n')
    {
    }

    return input == seq; // compare user input to sequence, if equal return true/won
}

bool shake(const std::string &monsterName)
{
    system("cls");
    std::cout << "The hallway goes quiet...\n"; // game intro
    std::cout << monsterName << " steps foward and slowly raises its hand toward you.\n\n";

    std::cout << "What do you do?\n"; // game instructions
    std::cout << "A) Lower your head and bow\n";
    std::cout << "B) Shake its hand confidently\n";
    std::cout << "C) Back away slowly\n\n";

    std::cout << "Your move: ";         // print prompt
    char choice = getCharChoice("ABC"); // gets input from user and checks if it's valid

    if (choice == 'A') // if user chooses A
        return true;   // return true = win

    return false; // else return false = lose
}
