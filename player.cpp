#include "player.h"

Player::Player(string charName) : Character(charName) {
    currentPlayerExperience = 0;
    maxExperienceForLevel = 10;
    gold = 0;
}

void Player::LevelUp() {
    if (currentPlayerExperience >= maxExperienceForLevel) {
        level++;
        strength += 2;
        intelligence += 1;
        dexterity += 1;
    }
}