#ifndef APPLICATION_H
#define APPLICATION_H

#include "Game.h"
#include "../Engine/Engine.h"

class Application
{
public:
    inline static Engine* EngineApi;
    
    static void Start()
    {
        const auto config = new Engine::Config{
            "Snake",
            sf::Vector2u{1280, 720},
            60,
            false
        };

        EngineApi = new Engine(config);

        Game game;

        game.Start();

        EngineApi->Run();
    }

    static void Close()
    {
        EngineApi->Dispose();

        delete EngineApi;
    }
};


#endif
