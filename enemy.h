#pragma once
#include "character.h"

class Enemy : public Character
{
    public:
        Enemy(string charName);
        static Enemy* CreateEnemy(string enemyType);
    private:
};