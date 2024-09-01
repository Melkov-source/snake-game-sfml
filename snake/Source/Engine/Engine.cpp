#include "Engine.h"

Engine::Engine(Config* config) : _config(config)
{
    this->SceneManagment = new SceneManager();
    
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

    this->SceneManagment->Update(this->_deltaTime.asSeconds());
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

    ImGui::SFML::Render(*this->_renderWindow);

    this->SceneManagment->Render(*this->_renderWindow);
    
    this->_renderWindow->display();
}

void Engine::Dispose()
{
    ImGui::SFML::Shutdown();
}
