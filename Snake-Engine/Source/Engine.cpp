#include "Engine.h"
#include "Debug/Logger.h"

Engine::Engine(Config* config) : _config(config)
{
    Scene = new SceneManager();
    
    Initialize();
}

void Engine::Initialize()
{
    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::BLUE, "Engine: Start initialization\n");

    InitializeRenderWindow();

    ImGui::SFML::Init(*_renderWindow);

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Initialized success Dear ImGui\n");

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::BLUE, "Engine: End initialization\n");
}

void Engine::InitializeRenderWindow()
{
    const auto windowSize = _config->WindowSize;

    const sf::VideoMode videoMode(windowSize.x, windowSize.y);

    _renderWindow = new sf::RenderWindow(videoMode, _config->Title);

    _renderWindow->setFramerateLimit(_config->TargetFrameRate);
    _renderWindow->setVerticalSyncEnabled(_config->IsVerticalSync);

    Debug::Logger::Log("Engine: Setup window size [x: $, y: $]", windowSize.x, windowSize.y);
    Debug::Logger::Log("Engine: Setup framerate limit: [$]", _config->TargetFrameRate);
    Debug::Logger::Log("Engine: Setup verical sync: [$]", _config->IsVerticalSync);

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Initialized success SFML Render Window");
}

void Engine::Run()
{
    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Run\n");

    while (_renderWindow->isOpen())
    {
        Update();
        Render();
    }
}

void Engine::Update()
{
    _deltaTime = _deltaTimeClock.restart();

    UpdateEvents();

    ImGui::SFML::Update(*_renderWindow, _deltaTime);

    Scene->Update(_deltaTime.asSeconds());
}

void Engine::UpdateEvents()
{
    while (_renderWindow->pollEvent(Event))
    {
        ImGui::SFML::ProcessEvent(*_renderWindow, Event);

        switch (Event.type)
        {
            case sf::Event::Closed:
                _renderWindow->close();
                break;
        }
    }
}

void Engine::Render()
{
    _renderWindow->clear();
    
    Scene->Render(*_renderWindow);
    
    ImGui::SFML::Render(*_renderWindow);
    
    _renderWindow->display();
}

sf::Vector2u Engine::GetWindowSize() const
{
    return _renderWindow->getSize();
}

void Engine::Close()
{
    _renderWindow->close();
    
    ImGui::SFML::Shutdown();
}
