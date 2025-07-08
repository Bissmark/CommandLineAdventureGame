#include "mage.h"

Mage::Mage(string charName) : Player(charName) {
    strength = 2;
    intelligence = 5;
    dexterity = 3;
    level = 1;
    maxHP = 20;
    currentHP = maxHP;
    maxMana = 50;
    currentMana = maxMana;
}