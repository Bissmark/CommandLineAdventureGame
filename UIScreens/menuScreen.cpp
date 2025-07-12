#include "menuScreen.h"

MenuScreen::MenuScreen() {
    currentState = GameState::MENU;
    currentStep = STEP_MENU;
}

MenuScreen::~MenuScreen() {

}

void MenuScreen::Update() {

}

void MenuScreen::Render() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | 
                                   ImGuiWindowFlags_NoCollapse |
                                   ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoTitleBar;
    
    // Center the window
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_Always);

    if (ImGui::Begin("##Menu", nullptr, window_flags)) {
        switch (currentStep) {
            case STEP_MENU:
                ImGui::Button("Start Game");
                ImGui::Button("Load Game");
                ImGui::Button("Settings");
                ImGui::Button("Quit Game");

                break;

            case STEP_SAVED_GAMES:
                ImGui::Button("Load Game 1");
                ImGui::Button("Back Button");

                break;

            case STEP_SETTINGS:
                ImGui::Button("Change Graphics");
                ImGui::Button("Change Sound");
                ImGui::Button("Back Button");

                break;

            case STEP_QUIT_GAME:
                ImGui::Button("Quit Game");

                break;
        }
    }
    ImGui::End();
}

GameState MenuScreen::GetNextState() {
    if (stateChanged) {
        stateChanged = false;
        return nextState;
    }
    return currentState;
}