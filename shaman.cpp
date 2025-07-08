#include "shaman.h"

Shaman::Shaman(string charName) : Player(charName) {
    strength = 3;
    intelligence = 3;
    dexterity = 3;
    level = 1;
    maxHP = 35;
    maxMana = 35;
}