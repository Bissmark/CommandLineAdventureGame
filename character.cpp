#include "character.h"

Character::Character(string charName) {
    name = charName;
    strength = 0;
    intelligence = 0;
    dexterity = 0;
    level = 1;
}

void Character::takeDamage(int damage) {
    currentHP -= damage;

    if (currentHP < 0) {
        currentHP = 0;
    }
}

void Character::heal(int amount) {
    currentHP += amount;

    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
}

bool Character::isAlive() const {
    return currentHP > 0;
}