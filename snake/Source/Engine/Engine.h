#pragma once

#include <filesystem>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "imgui-SFML.h"

#include "Core/Scenes/SceneManager.h"

class Engine
{
public:
    struct Config
    {
        std::string Title{"None"};
        sf::Vector2u WindowSize{};
        unsigned int TargetFrameRate{60};
        bool IsVerticalSync{false};
    };

    const Core::Scenes::SceneManager* SceneManager;

    explicit Engine(Config* config);

    void Run();
    void Dispose();

private:
    Config* _config;
    sf::RenderWindow* _renderWindow;
    sf::Event _event;
    sf::Clock _deltaTimeClock;
    sf::Time _deltaTime;
    
    void Initialize();
    void InitializeRenderWindow();
    void Update();
    void Render();
};
