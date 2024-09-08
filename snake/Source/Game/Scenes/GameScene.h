#pragma once
#include "../../Engine/Core/Scenes/Scene.h"
#include "../Debug/FPSCounter.h"
#include "Entities/Snake.h"

class GameScene final : public Scene
{
public:
    GameScene();
    ~GameScene() override;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
private:
    sf::Texture* _pGrassTexture;
    FPSCounter _fpsCounter;

    Snake* _snake;
};
