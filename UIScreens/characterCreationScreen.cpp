#include "characterCreationScreen.h"

CharacterCreationScreen::CharacterCreationScreen() {
    currentState = GameState::CHARACTER_CREATION;
    currentStep = STEP_NAME_INPUT;
    stepComplete = false;
    player = nullptr;

    m_characterName = "";
    m_classSelection = "";
    memset(m_nameBuffer, 0, sizeof(m_nameBuffer));
    memset(m_classBuffer, 0, sizeof(m_classBuffer));
}

CharacterCreationScreen::~CharacterCreationScreen() {

}

void CharacterCreationScreen::Update() {
    HandleCurrentStep();
}

void CharacterCreationScreen::Render() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | 
                                   ImGuiWindowFlags_NoCollapse |
                                   ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoTitleBar;
    
    // Center the window
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_Always);

    UpdateBuffersFromStrings();

    if (ImGui::Begin("##CharacterCreation", nullptr, window_flags)) {
        switch (currentStep) {
            case STEP_NAME_INPUT:
                CenterText("First please create a name for your character:");
                ImGui::Spacing();
                ImGui::Spacing();
                
                CenterNextItem(400);
                ImGui::SetNextItemWidth(400);
                if (ImGui::InputText("##CharacterName", m_nameBuffer, sizeof(m_nameBuffer))) {
                    m_characterName = std::string(m_nameBuffer);
                }
                ImGui::Spacing();

                if (stepComplete) {
                    CenterNextItem(50);
                    if (ImGui::ArrowButton("##ContinueName", ImGuiDir_Right)) {
                        NextStep();
                    }
                }
                break;
                
            case STEP_WELCOME_LAND:
                CenterText(("Welcome to Adventure Land, " + m_characterName).c_str());
                ImGui::Spacing();
                ImGui::Spacing();

                if (stepComplete) {
                    CenterNextItem(50);
                    if (ImGui::ArrowButton("##ContinueName", ImGuiDir_Right)) {
                        NextStep();
                    }
                }
                break;

            case STEP_DESCRIPTION:
                CenterText("In this land you will have the ability to adventure around the world fighting monsters, collecting loot and saving helpless people");
                ImGui::Spacing();
                ImGui::Spacing();
                
                if (stepComplete) {
                    CenterNextItem(50);
                    if (ImGui::ArrowButton("##ContinueName", ImGuiDir_Right)) {
                        NextStep();
                    }
                }
                break;

            case STEP_CLASS_PROMPT:
                CenterText("First of all, what sort of class would you like to be?");
                CenterText("You can be a Warrior, Mage, Rogue or Shaman");
                ImGui::Spacing();
                ImGui::Spacing();

                CenterNextItem(400);
                ImGui::SetNextItemWidth(400);
                if (ImGui::InputText("##CharacterName", m_classBuffer, sizeof(m_classBuffer))) {
                    m_classSelection = std::string(m_classBuffer);
                    m_classSelection[0] = toupper(m_classSelection[0]);
                }
                ImGui::Spacing();
                
                if (stepComplete) {
                    CenterNextItem(50);
                    if (ImGui::ArrowButton("##ContinueName", ImGuiDir_Right)) {
                        CreatePlayer();
                        NextStep();
                    }
                }
                break;
                
            case STEP_COMPLETE:
                CenterText("Character Creation Complete");
                ImGui::Spacing();
                ImGui::Spacing();
                
                std::string nameText = "Name: " + m_characterName;
                CenterText(nameText.c_str());
                std::string classText = "Class: " + m_classSelection;
                CenterText(classText.c_str());
                ImGui::Spacing();
                
                if (player) {
                    ImGui::Spacing();
                    ImGui::Text("Level: %d", player->getLevel());
                    ImGui::Text("Strength: %d", player->getStrength());
                    ImGui::Text("Intelligence: %d", player->getIntelligence());
                    ImGui::Text("Dexterity: %d", player->getDexterity());
                }
                ImGui::Spacing();
                ImGui::Spacing();

                CenterNextItem(120);
                if (ImGui::Button("Start Adventure")) {
                    ChangeState(GameState::COMBAT);
                }
                break;
        }
    }
    ImGui::End();
}

GameState CharacterCreationScreen::GetNextState() {
    if (stateChanged) {
        stateChanged = false;
        return nextState;
    }
    return currentState;
}

void CharacterCreationScreen::HandleCurrentStep() {
    switch (currentStep) {
        case STEP_NAME_INPUT:
            stepComplete = (strlen(m_nameBuffer) > 0);
            break;
        case STEP_CLASS_PROMPT:
            stepComplete = !m_classSelection.empty();
            break;
        default:
            stepComplete = true;
            break;
    }
}

void CharacterCreationScreen::NextStep() {
    currentStep = static_cast<CreationStep>(static_cast<int>(currentStep) + 1);
    stepComplete = false;
}

void CharacterCreationScreen::CreatePlayer() {
    if (player) {
        delete player;
    }
    
    if (m_classSelection == "Warrior") {
        player = new Warrior(m_characterName);
    } else if (m_classSelection == "Mage") {
        player = new Mage(m_characterName);
    } else if (m_classSelection == "Rogue") {
        player = new Rogue(m_characterName);
    } else if (m_classSelection == "Shaman") {
        player = new Shaman(m_characterName);
    }
}

void CharacterCreationScreen::UpdateBuffersFromStrings() {
    strcpy_s(m_nameBuffer, sizeof(m_nameBuffer), m_characterName.c_str());
    strcpy_s(m_classBuffer, sizeof(m_classBuffer), m_classSelection.c_str());
}

void CharacterCreationScreen::CenterText(const char* text) {
    float textWidth = ImGui::CalcTextSize(text).x;
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - textWidth) / 2.0f);
    ImGui::Text("%s", text);
}

void CharacterCreationScreen::CenterNextItem(float itemWidth) {
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - itemWidth) / 2.0f);
}

