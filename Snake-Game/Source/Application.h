#pragma once

#include "Engine.h"
#include "Scenes/MenuScene.h"

class Application
{
  public:
    static void Start()
    {
        const auto config = new Engine::Config{"Snake-Game", sf::Vector2u{1280, 720}, 60, false};
        _engine = new Engine(config);

        SceneManager::LoadScene<MenuScene>();

        _engine->Run();
    }

    static void Close()
    {
        _engine->Close();

        delete _engine;
    }

    static sf::Vector2u GetWindowSize()
    {
        return _engine->GetWindowSize();
    }

  private:
    inline static Engine *_engine;
};
