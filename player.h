#pragma once
#include "character.h"
#include "imgui/imgui.h"

class Player : public Character
{
    public:
        Player(string charName);
        void LevelUp();

    private:
};