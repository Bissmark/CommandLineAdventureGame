#pragma once

class Player
{
    public:
        Player();

        int playerLevel;

    private:
        enum class PlayerType { WARRIOR, MAGE, ROGUE, SHAMAN };
};