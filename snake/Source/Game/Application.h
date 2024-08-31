#ifndef APPLICATION_H
#define APPLICATION_H

#include "Game.h"
#include "../Engine/Engine.h"

class Application
{
public:
    static void Start()
    {
        const auto config = new Engine::Config{
            "Snake",
            sf::Vector2u{400, 600},
            60,
            false
        };

        _engine = new Engine(config);

        Game game{*_engine};

        game.Start();

        _engine->Run();
    }

    static void Close()
    {
    }

private:
    inline static Engine* _engine;
};


#endif
