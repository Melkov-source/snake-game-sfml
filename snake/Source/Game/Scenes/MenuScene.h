#pragma once
#include "../../Engine/Core/Scenes/Scene.h"

class MenuScene final : public Scene
{
public:
    MenuScene();
    
    void Initialize() override;
    void Update(const float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
    void Dispose() override;
};
