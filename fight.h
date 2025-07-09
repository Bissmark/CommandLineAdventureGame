#pragma once
#include <iostream>
#include <algorithm>
#include "player.h"
#include "enemy.h"
using namespace std;

class Fight {
    public:
        Fight(Player* p, string enemyType);
        ~Fight();
        void FightMenu();
        void FightScreen();
        void PlayerTurn();
        void EnemyTurn();
        void Run();
    private:
        Player* player;
        Enemy* enemy;
        bool fightActive;
        int whosTurn;
};