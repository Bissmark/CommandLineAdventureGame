#pragma once
#include <iostream>
using namespace std;

class Character
{
    public:
        Character(string charName);

        string getName() const { return name; }
        int getLevel() const { return level; }
        int getStrength() const { return strength; }
        int getIntelligence() const { return intelligence; }
        int getDexterity() const { return dexterity; }
        int getHP() const { return currentHP; }
        int getExperience() const { return experienceEnemy; }
        int getGold() const { return gold; }
        int getPlayerGold() const { return currentGold; }

        void takeDamage(int damage);
        void heal(int amount);
        bool isAlive() const;
        int currentPlayerExperience;
        int currentGold;

    protected:
        string name;
        int strength;
        int intelligence;
        int dexterity;
        int gold;
        int level;
        int maxHP;
        int currentHP;
        int maxMana;
        int currentMana;
        int experienceEnemy;
        int maxExperienceForLevel;
};