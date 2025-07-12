#pragma once
#include "baseScreen.h"
#include "../fight.h"

class CombatScreen : public BaseScreen
{
    public:
        CombatScreen(Player* p);
        ~CombatScreen();

        void Update() override;
        void Render() override;
        GameState GetNextState() override;

    private:
        Player* player;
        Fight* currentFight;

        void RenderCombatUI();
        void StartNewFight();
};