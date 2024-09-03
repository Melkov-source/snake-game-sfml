#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Engine/Engine.h"

class MenuScene;

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

        EngineApi->SceneManagement->LoadScene<MenuScene>();

        EngineApi->Run();
    }

    static void Close()
    {
        EngineApi->Dispose();

        delete EngineApi;
    }
};


#endif
