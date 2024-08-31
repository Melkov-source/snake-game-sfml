#pragma once

#include <filesystem>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "imgui-SFML.h"

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

    explicit Engine(Config* config);
    ~Engine();

    void Run();
    void Dispose();

private:
    void Initialize();
    void Update();
    void Render();

    void InitializeRenderWindow();

    Config* _config;
    sf::RenderWindow* _renderWindow;
    sf::Event _event;
    sf::Clock _deltaTimeClock;
    sf::Time _deltaTime;
};
