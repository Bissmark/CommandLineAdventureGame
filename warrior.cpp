#include "warrior.h"

Warrior::Warrior(string charName) : Player(charName) {
    strength = 5;
    intelligence = 2;
    dexterity = 3;
    level = 1;
    maxHP = 50;
    currentHP = maxHP;
    maxMana = 20;
    currentMana = maxMana;
}