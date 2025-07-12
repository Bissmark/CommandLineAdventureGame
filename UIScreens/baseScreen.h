#pragma once
#include <SDL3/SDL.h>
#include "../imgui/imgui.h"
#include "../player.h"
#include "gameState.h"

class BaseScreen
{
    public:
        virtual ~BaseScreen() = default;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual GameState GetNextState() { return currentState; }
        virtual bool ShouldExit() { return shouldExit; }

    protected:
        GameState currentState;
        bool shouldExit = false;
        bool stateChanged = false;
        GameState nextState;

        void ChangeState(GameState newState) {
            nextState = newState;
            stateChanged = true;
        }
};