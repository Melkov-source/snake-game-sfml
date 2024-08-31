#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Engine/Engine.h"

namespace Game
{
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

            _engine->Run();
        }

        static void Close()
        {
        }

    private:
        inline static Engine* _engine;
    };
}

#endif
