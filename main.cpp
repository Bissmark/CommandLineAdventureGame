#include <iostream>
#include "player.h"
#include "warrior.h"
#include "mage.h"
#include "rogue.h"
#include "shaman.h"
#include "dice.h"
#include "startStory.h"
using namespace std;

int main() 
{
    Player* player = nullptr;
    Dice dice;
    
    string charName;
    string classSelection;
    
    cout << "\n" << "-----------------------------------------------------------------------------" << endl;
    cout << "- Welcome to Adventure Game, First please create a name for your character: -" << endl;
    cin >> charName;
    
    cout << "Welcome to ____ Land " << charName << endl;
    cout << "In this land you will have the ability to adventure around the world fighting monsters, collecting loot and saving helpless people" << endl;
    cout << "First of all, what sort of class would you like to be, You can be a Warrior, Mage, Rogue or Shaman" << endl;
    cin >> classSelection;

    transform(classSelection.begin(), classSelection.end(), classSelection.begin(), ::tolower);
    
    if (classSelection == "warrior") {
        player = new Warrior(charName);
    } else if (classSelection == "mage") {
        player = new Mage(charName); 
    } else if (classSelection == "rogue") {
        player = new Rogue(charName);
    } else if (classSelection == "shaman") {
        player = new Shaman(charName);
    }
    
    cout << "You have selected a " << classSelection << endl;
    cout << "Your stats at your current level of " << player->getLevel() << " is " << player->getStrength() << " Strength, " << player->getIntelligence() << " Intelligence, and " << player->getDexterity() << " Dexterity" << endl;
    
    StartStory startStory(player);
    startStory.RandomEncounter();

    // dice.Roll();

    delete player;
    return 0;
}