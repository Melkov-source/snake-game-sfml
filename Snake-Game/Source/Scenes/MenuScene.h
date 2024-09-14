#pragma once

#include "imgui.h"

#include "Core/Scenes/SceneManager.h"
#include "Debug/Logger.h"

class MenuScene final : public Scene
{
  public:
    ~MenuScene() override;

    void Initialize() override;
    void Update(const float deltaTime) override;
    void Render(sf::RenderTarget &renderTarget) override;
};
