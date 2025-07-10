#include "player.h"

Player::Player(string charName) : Character(charName) {
    currentPlayerExperience = 0;
    maxExperienceForLevel = 10;
    gold = 0;
}

void Player::LevelUp() {
    if (currentPlayerExperience >= maxExperienceForLevel) {
        level++;
        cout << "Congratulations, you have leveled up!" << endl;
        cout << "You are level: " << level << endl;
        strength += 2;
        intelligence += 1;
        dexterity += 1;
        cout << "Your stats have increased to" << endl; 
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl; 
        cout << "Dexterity: " << dexterity << endl;
    }
}