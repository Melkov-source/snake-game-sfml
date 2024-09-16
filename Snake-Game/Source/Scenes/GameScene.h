#pragma once
#include "Core/Scenes/SceneManager.h"
#include "Debug/FPSCounter.h"

#include "MenuScene.h"

#include "Entities/Snake.h"
#include "Entities/Map.h"
#include "Items/Apple.h"

class Map;

class GameScene final : public Scene
{
  public:
    GameScene();
    ~GameScene() override;

    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderTarget &renderTarget) override;

  private:
    sf::Texture *_pGrassTexture;
    FPSCounter _fpsCounter;

    Map *_map;
    Snake *_snake;
};
