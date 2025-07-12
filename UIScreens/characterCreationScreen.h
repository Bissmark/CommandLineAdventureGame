#pragma once
#include "baseScreen.h"
#include "../warrior.h"
#include "../mage.h"
#include "../rogue.h"
#include "../shaman.h"

class CharacterCreationScreen : public BaseScreen
{
    public:
        CharacterCreationScreen();
        ~CharacterCreationScreen();

        void Update() override;
        void Render() override;
        GameState GetNextState() override;

        Player* GetCreatedPlayer() { return player; }

    private:
        enum CreationStep {
            STEP_NAME_INPUT = 0,
            STEP_WELCOME_LAND = 1,
            STEP_DESCRIPTION = 2,
            STEP_CLASS_PROMPT = 3,
            STEP_COMPLETE = 4
        };

        CreationStep currentStep;
        bool stepComplete;

        std::string m_characterName;
        std::string m_classSelection;
        char m_nameBuffer[256];
        char m_classBuffer[256];
        Player* player;

        void HandleCurrentStep();
        void NextStep();
        void CreatePlayer();
        void UpdateBuffersFromStrings();
        void CenterText(const char* text);
        void CenterNextItem(float itemWidth);
};