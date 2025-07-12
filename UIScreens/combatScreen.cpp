#include "combatScreen.h"

CombatScreen::CombatScreen(Player* p) : player(p) {
    currentState = GameState::COMBAT;
    currentFight = nullptr;
    StartNewFight();
}

CombatScreen::~CombatScreen() {
    if (currentFight) {
        delete currentFight;
    }
}

void CombatScreen::Update() {

}

void CombatScreen::Render() {
    RenderCombatUI();
}

void CombatScreen::RenderCombatUI() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | 
                                   ImGuiWindowFlags_NoCollapse |
                                   ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoTitleBar;
    
    // Center the window
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_Always);

    if (ImGui::Begin("##Combat", nullptr, window_flags)) {
        if (currentFight && currentFight->enemy) {
            // Combat UI
            ImGui::Text("=== COMBAT ===");
            ImGui::Separator();
            
            // Enemy info
            ImGui::Text("Enemy: %s (Level %d)", 
                       currentFight->enemy->getName().c_str(), 
                       currentFight->enemy->getLevel());
            ImGui::Text("Enemy HP: %d", currentFight->enemy->getHP());
            
            ImGui::Spacing();
            
            // Player info
            ImGui::Text("Player: %s (Level %d)", 
                       player->getName().c_str(), 
                       player->getLevel());
            ImGui::Text("Player HP: %d", player->getHP());
            
            ImGui::Spacing();
            ImGui::Separator();
            
            // Combat actions
            if (ImGui::Button("Attack", ImVec2(100, 40))) {
                // Call your existing combat logic
                currentFight->PlayerTurn();
                if (currentFight->enemy->isAlive()) {
                    currentFight->EnemyTurn();
                }
            }
            
            ImGui::SameLine();
            if (ImGui::Button("Run Away", ImVec2(120, 40))) {
                currentFight->Run();
                ChangeState(GameState::STORY);  // Or back to story
            }
            
            // Check for combat end
            if (!currentFight->enemy->isAlive()) {
                ImGui::Spacing();
                ImGui::Text("Victory! You defeated the enemy!");
                if (ImGui::Button("Continue Adventure", ImVec2(200, 40))) {
                    StartNewFight();  // Or change to story state
                }
            }
            
            if (!player->isAlive()) {
                ImGui::Spacing();
                ImGui::Text("You have been defeated!");
                if (ImGui::Button("Game Over", ImVec2(100, 40))) {
                    ChangeState(GameState::GAME_OVER);
                }
            }
        }
    }
    ImGui::End();
}

void CombatScreen::StartNewFight() {
    if (currentFight) {
        delete currentFight;
    }
    currentFight = new Fight(player, "Gnoll");
}

GameState CombatScreen::GetNextState() {
    if (stateChanged) {
        stateChanged = false;
        return nextState;
    }
    return currentState;
}