#include "displayWindow.h"

DisplayWindow::DisplayWindow(int width, int height, const std::string& title) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cerr << "SDL Init failed: " << SDL_GetError() << std::endl;
        m_isClosed = true;
        return;
    }

    m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
    if (!m_window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        m_isClosed = true;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, nullptr);
    if (!m_renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        m_isClosed = true;
        return;
    }

    m_isClosed = false;

    std::cout << "Window and renderer created successfully!" << std::endl;

    InitImGui();

    currentState = GameState::CHARACTER_CREATION;
    currentScreen = new CharacterCreationScreen();
    gamePlayer = nullptr;
}

DisplayWindow::~DisplayWindow() {
    ShutdownImGui();

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
    if (gamePlayer != nullptr) {
        delete gamePlayer;
    }
    SDL_Quit();
}

bool DisplayWindow::IsClosed()
{
    return m_isClosed;
}

void DisplayWindow::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);

        if (event.type == SDL_EVENT_QUIT) {
            m_isClosed = true;
        }
        if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
            m_isClosed = true;
        }
    }

    if (currentScreen) {
        currentScreen->Update();

        GameState nextState = currentScreen->GetNextState();
        if (nextState != currentState) {
            ChangeScreen(nextState);
        }
    }
}

void DisplayWindow::Render() {
    SDL_SetRenderDrawColor(m_renderer, 25, 25, 50, 255);
    SDL_RenderClear(m_renderer);

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    
    if (currentScreen) {
        currentScreen->Render();
    }
    
    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_renderer);
    SDL_RenderPresent(m_renderer);
}

void DisplayWindow::ChangeScreen(GameState newState) {
    // Handle player transfer between screens
    if (currentState == GameState::CHARACTER_CREATION && newState == GameState::COMBAT) {
        CharacterCreationScreen* charScreen = dynamic_cast<CharacterCreationScreen*>(currentScreen);
        if (charScreen) {
            gamePlayer = charScreen->GetCreatedPlayer();
        }
    }
    
    // Clean up old screen
    delete currentScreen;
    currentScreen = nullptr;
    
    // Create new screen
    currentState = newState;
    switch (newState) {
        case GameState::CHARACTER_CREATION:
            currentScreen = new CharacterCreationScreen();
            break;
        case GameState::COMBAT:
            currentScreen = new CombatScreen(gamePlayer);
            break;
        // Add other states as needed
        default:
            break;
    }
}

void DisplayWindow::InitImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    
    //ImGui::StyleColorsDark();

    io.Fonts->AddFontFromFileTTF("C:\\Users\\Gosh_\\Desktop\\Programming\\Projects\\C++\\adventureGame\\fonts\\Montserrat-VariableFont_wght.ttf", 26.0f);
    
    ImGui_ImplSDL3_InitForSDLRenderer(m_window, m_renderer);
    ImGui_ImplSDLRenderer3_Init(m_renderer);
}

void DisplayWindow::ShutdownImGui() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

// bool DisplayWindow::IsElementVisible(const std::string& id, float& alpha) {
//     float currentTime = SDL_GetTicks() / 1000.0f;
//     float elapsed = currentTime - m_gameStartTime;
    
//     for (auto& element : m_timedElements) {
//         if (element.id == id) {
//             if (elapsed >= element.showTime) {
//                 float fadeTime = elapsed - element.showTime;
//                 alpha = std::min(fadeTime / 0.5f, 1.0f); // 0.5s fade-in
//                 return alpha > 0.0f;
//             }
//         }
//     }
//     alpha = 0.0f;
//     return false;
// }