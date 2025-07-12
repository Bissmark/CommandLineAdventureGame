#pragma once
#include <iostream>
#include <algorithm>
#include "player.h"
#include "enemy.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl3.h"
#include "imgui/imgui_impl_sdlrenderer3.h"
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
        Enemy* enemy;
    private:
        Player* player;
        bool fightActive;
        int whosTurn;
};