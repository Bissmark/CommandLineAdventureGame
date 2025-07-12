#include <iostream>
#include "player.h"
#include "warrior.h"
#include "mage.h"
#include "rogue.h"
#include "shaman.h"
#include "dice.h"
#include "startStory.h"
#include "UIScreens/displayWindow.h"
using namespace std;

#define WIDTH 1200
#define HEIGHT 800

int main() 
{
    DisplayWindow display(WIDTH, HEIGHT, "Adventure Game");
    if (display.IsClosed()) {
        std::cerr << "Failed to create window!" << std::endl;
        return -1;
    }

    Player* player = nullptr;
    Dice dice;
    
    string charName;
    string classSelection;

    while (!display.IsClosed())
    {
        display.Update();

        display.Render();

        SDL_Delay(16);
        // cout << "\n" << "-----------------------------------------------------------------------------" << endl;
        // cout << "- Welcome to Adventure Game, First please create a name for your character: -" << endl;
        // cin >> charName;
        
        // cout << "Welcome to ____ Land " << charName << endl;
        // cout << "In this land you will have the ability to adventure around the world fighting monsters, collecting loot and saving helpless people" << endl;
        // cout << "First of all, what sort of class would you like to be, You can be a Warrior, Mage, Rogue or Shaman" << endl;
        // cin >> classSelection;
    
        // transform(classSelection.begin(), classSelection.end(), classSelection.begin(), ::tolower);
        
        // if (classSelection == "warrior") {
        //     player = new Warrior(charName);
        // } else if (classSelection == "mage") {
        //     player = new Mage(charName); 
        // } else if (classSelection == "rogue") {
        //     player = new Rogue(charName);
        // } else if (classSelection == "shaman") {
        //     player = new Shaman(charName);
        // }
        
        // cout << "You have selected a " << classSelection << endl;
        // cout << "Your stats at your current level of " << player->getLevel() << " is " << player->getStrength() << " Strength, " << player->getIntelligence() << " Intelligence, and " << player->getDexterity() << " Dexterity" << endl;
        
        //StartStory startStory(player);
        //startStory.RandomEncounter();

    }

    delete player;
    return 0;
}