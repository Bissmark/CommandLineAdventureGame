#pragma once
#include "basescreen.h"

class MenuScreen : public BaseScreen
{
    public:
        MenuScreen();
        ~MenuScreen();

        void Update() override;
        void Render() override;
        GameState GetNextState() override;
    private:
        enum MenuStep {
            STEP_MENU = 0,
            STEP_START_GAME = 1,
            STEP_SAVED_GAMES = 2,
            STEP_SETTINGS = 3,
            STEP_QUIT_GAME = 4
        };

        MenuStep currentStep;
};