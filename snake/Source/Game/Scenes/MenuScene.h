#pragma once
#include "../../Engine/Core/Scenes/Scene.h"

class MenuScene final : public Scene
{
public:
    ~MenuScene() override;
    
    void Initialize() override;
    void Update(const float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
};

