#pragma once
#include <iostream>
#include <vector>
#include "fight.h"
#include "player.h"

using namespace std;

class StartStory {
    public:
        StartStory(Player* player);
        void RandomEncounter();
        string GetRandomEnemy();
    private:
        Player* player;
};