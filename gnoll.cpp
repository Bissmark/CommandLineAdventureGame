#include "gnoll.h"

Gnoll::Gnoll(string charName) : Enemy(charName) {
    strength = 2;
    intelligence = 1;
    dexterity = 1;
    level = 1;
    maxHP = 15;
    currentHP = maxHP;
    maxMana = 10;
    currentMana = maxMana;
    currentExperience = 5;
}