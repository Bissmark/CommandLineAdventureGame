#include "rogue.h"

Rogue::Rogue(string charName) : Player(charName) {
    strength = 2;
    intelligence = 3;
    dexterity = 5;
    level = 1;
    maxHP = 30;
    currentHP = maxHP;
    maxMana = 35;
    currentMana = maxMana;
}