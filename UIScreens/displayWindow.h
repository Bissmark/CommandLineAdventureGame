#pragma once
#include <SDL3/SDL.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl3.h"
#include "../imgui/imgui_impl_sdlrenderer3.h"
#include "baseScreen.h"
#include "characterCreationScreen.h"
#include "combatScreen.h"

class DisplayWindow
{
    public:
        DisplayWindow(int width, int height, const std::string& title);
        ~DisplayWindow();

        void Update();
        void Render();
        bool IsClosed();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isClosed;

        BaseScreen* currentScreen;
        GameState currentState;
        Player* gamePlayer;

        void InitImGui();
        void ShutdownImGui();
        void ChangeScreen(GameState newState);
};