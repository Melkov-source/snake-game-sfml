#include "Engine.h"
#include "Debug/Logger.h"

Engine::Engine(Config* config) : _config(config)
{
    this->Scene = new SceneManager();
    
    this->Initialize();
}

void Engine::Initialize()
{
    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::BLUE, "Engine: Start initialization\n");

    this->InitializeRenderWindow();

    ImGui::SFML::Init(*this->_renderWindow);

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Initialized success Dear ImGui\n");

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::BLUE, "Engine: End initialization\n");
}

void Engine::InitializeRenderWindow()
{
    const auto windowSize = this->_config->WindowSize;

    const sf::VideoMode videoMode(windowSize.x, windowSize.y);

    this->_renderWindow = new sf::RenderWindow(videoMode, this->_config->Title);

    this->_renderWindow->setFramerateLimit(this->_config->TargetFrameRate);
    this->_renderWindow->setVerticalSyncEnabled(this->_config->IsVerticalSync);

    Debug::Logger::Log("Engine: Setup window size [x: $, y: $]", windowSize.x, windowSize.y);
    Debug::Logger::Log("Engine: Setup framerate limit: [$]", this->_config->TargetFrameRate);
    Debug::Logger::Log("Engine: Setup verical sync: [$]", this->_config->IsVerticalSync);

    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Initialized success SFML Render Window");
}

void Engine::Run()
{
    Debug::Logger::LogColor(Debug::Logger::LOG_COLOR::GREEN, "Engine: Run\n");

    while (this->_renderWindow->isOpen())
    {
        this->Update();
        this->Render();
    }
}

void Engine::Update()
{
    this->_deltaTime = this->_deltaTimeClock.restart();

    this->UpdateEvents();

    ImGui::SFML::Update(*this->_renderWindow, this->_deltaTime);

    this->Scene->Update(this->_deltaTime.asSeconds());
}

void Engine::UpdateEvents()
{
    while (this->_renderWindow->pollEvent(this->_event))
    {
        ImGui::SFML::ProcessEvent(*this->_renderWindow, this->_event);

        if(this->_event.type == sf::Event::Closed)
        {
            this->_renderWindow->close();
        } else if(this->_event.type == sf::Event::KeyPressed)
        {
            this->KeyPressed = this->_event.key.code;
        }
    }
}

void Engine::Render()
{
    this->_renderWindow->clear();
    
    this->Scene->Render(*this->_renderWindow);
    
    ImGui::SFML::Render(*this->_renderWindow);
    
    this->_renderWindow->display();
}

sf::Vector2u Engine::GetWindowSize() const
{
    return this->_renderWindow->getSize();
}

void Engine::Close()
{
    _renderWindow->close();
    
    ImGui::SFML::Shutdown();
}
