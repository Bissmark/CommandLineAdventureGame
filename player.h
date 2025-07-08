#pragma once

class Player
{
    public:
        Player();

        int playerLevel;
        int playerHP;

    private:
        enum class PlayerType { WARRIOR, MAGE, ROGUE, SHAMAN };
};