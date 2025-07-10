#pragma once
#include "character.h"

class Player : public Character
{
    public:
        Player(string charName);
        void LevelUp();

    private:
};