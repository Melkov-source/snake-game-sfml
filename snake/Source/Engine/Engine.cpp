#include "Engine.h"

Engine::Engine(Config* config) : _config(config)
{
    this->Scene = new SceneManager();
    
    this->Initialize();
}


void Engine::Initialize()
{
    this->InitializeRenderWindow();

    ImGui::SFML::Init(*this->_renderWindow);
}

void Engine::InitializeRenderWindow()
{
    const auto windowSize = this->_config->WindowSize;

    const sf::VideoMode videoMode(windowSize.x, windowSize.y);

    this->_renderWindow = new sf::RenderWindow(videoMode, this->_config->Title);

    this->_renderWindow->setFramerateLimit(this->_config->TargetFrameRate);
    this->_renderWindow->setVerticalSyncEnabled(this->_config->IsVerticalSync);
}

void Engine::Run()
{
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


void Engine::Dispose()
{
    _renderWindow->close();
    
    ImGui::SFML::Shutdown();
}
