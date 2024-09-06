#include "GameScene.h"

#include "Grass.h"
#include "imgui.h"
#include "../Application.h"
#include "../Player.h"
#include "../../Engine/Core/Assets/AssetsManager.h"

GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
    constexpr unsigned int tileSize = 64;
    const sf::Vector2u windowSize = Application::Core->GetWindowSize();

    constexpr float scale = 0.4f;

    for (unsigned int x = 0; x < windowSize.x / scale; x += tileSize)
    {
        for (unsigned int y = 0; y < windowSize.y / scale; y += tileSize)
        {
            const auto grass = new Grass();
            
            grass->setPosition(sf::Vector2f(x * scale, y * scale));
            grass->setScale(sf::Vector2f(scale, scale));
        }
    }
    
    Scene::Initialize();
}

void GameScene::Update(float deltaTime)
{
    Scene::Update(deltaTime);

    ImGui::Begin("Game", nullptr, ImGuiWindowFlags_NoTitleBar);
    this->_fpsCounter.DrawFpsText(deltaTime);

    if(ImGui::Button("Menu"))
    {
        Application::Core->Scene->LoadScene<MenuScene>();
    }
    ImGui::End();
}

void GameScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}
