#include <iostream>
#include "player.h"
#include "dice.h"
using namespace std;

int main() 
{
    Player player;
    Dice dice;

    string charName;
    string classSelection;
    int startStrength = 0;
    int startIntelligence = 0;
    int startDexterity = 0;

    cout << "\n" << "-----------------------------------------------------------------------------" << endl;
    cout << "- Welcome to Adventure Game, First please create a name for your character: -" << endl;
    cin >> charName;

    cout << "Welcome to ____ Land " << charName << endl;
    cout << "In this land you will have the ability to adventure around the world fighting monsters, collecting loot and saving helpless people" << endl;
    cout << "First of all, what sort of class would you like to be, You can be a Warrior, Mage, Rogue or Shaman" << endl;
    cin >> classSelection;

    cout << "You have selected a " << classSelection << endl;
    cout << "Your stats at your current level of " << player.playerLevel << " is " << startStrength << " Strength, " << startIntelligence << " Intelligence, and " << startDexterity << " Dexterity" << endl;

    dice.Roll();
    dice.Roll();
    dice.Roll();
    dice.Roll();
    dice.Roll();
    dice.Roll();



    return 0;
}