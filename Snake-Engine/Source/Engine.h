#pragma once

#include <filesystem>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include "Core/Scenes/SceneManager.h"
#include "Core/Assets/AssetsManager.h"
#include "Debug/Logger.h"

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

    sf::Event Event;

    explicit Engine(Config* config);

    void Run();
    void Close();

    sf::Vector2u GetWindowSize() const;

private:
    Config* _config;
    sf::RenderWindow* _renderWindow;
    
    sf::Clock _deltaTimeClock;
    sf::Time _deltaTime;
    
    void Initialize();
    void InitializeRenderWindow();
    void Update();
    void UpdateEvents();
    void Render();
};