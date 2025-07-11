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
}

DisplayWindow::~DisplayWindow() {
    ShutdownImGui();

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window) {
        SDL_DestroyWindow(m_window);
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
}

void DisplayWindow::Render() {
    SDL_SetRenderDrawColor(m_renderer, 25, 25, 50, 255);
    SDL_RenderClear(m_renderer);

    RenderImGui();
    
    SDL_RenderPresent(m_renderer);
}

void DisplayWindow::InitImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    ImGui::StyleColorsDark();
    
    ImGui_ImplSDL3_InitForSDLRenderer(m_window, m_renderer);
    ImGui_ImplSDLRenderer3_Init(m_renderer);
}

void DisplayWindow::ShutdownImGui() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

void DisplayWindow::RenderImGui() {
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    if (ImGui::Begin("Adventure Game")) {
        ImGui::Text("Welcome to your Adventure!");
    }

    ImGui::End();
    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_renderer);
}