#pragma once

#include "Engine.h"
#include "Scenes/MenuScene.h"

int main()
{
    const auto config = new Engine::Config
    {
        "Snake",
        sf::Vector2u{1280, 720},
        60,
        false
    };
    
    Engine engine(config);

    engine.Scene->LoadScene<MenuScene>();
    
    engine.Run();

    return 0;
}

