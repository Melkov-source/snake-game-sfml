#pragma once
#include "../../Engine/Core/Scenes/Scene.h"

class GameScene final : public Scene
{
public:
    ~GameScene() override;
    
    void Load() override;
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
    void Dispose() override;
};
