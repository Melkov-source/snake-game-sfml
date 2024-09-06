#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Engine/Engine.h"

class MenuScene;

class Application
{
public:
    inline static Engine* Core;
    
    static void Start()
    {
        const auto config = new Engine::Config{
            "Snake",
            sf::Vector2u{1280, 720},
            60,
            false
        };

        Core = new Engine(config);

        Core->Scene->LoadScene<MenuScene>();

        Core->Run();
    }

    static void Close()
    {
        Core->Close();

        delete Core;
    }
};


#endif
