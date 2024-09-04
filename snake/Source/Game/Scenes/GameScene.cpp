#include "GameScene.h"

#include "imgui.h"
#include "../Application.h"
#include "../Player.h"
#include "../../Engine/Core/Assets/AssetsManager.h"

GameScene::~GameScene()
{
    Scene();
}

void GameScene::Load()
{
    Scene::Load();
    
    this->_pGrassTexture = AssetsManager::LoadTexture("assets/textures/game-atlass.png", {0, 0, 64, 64});
}

void GameScene::Initialize()
{
    const unsigned int tileSize = 64;
    const sf::Vector2u windowSize = Application::Core->GetWindowSize();

    const float scale = 0.4f;

    const auto player = new Player();

    const auto playerLayer = player->AddComponent<LayerComponent>();

    playerLayer->Order = 1;

    for (unsigned int x = 0; x < windowSize.x / scale; x += tileSize)
    {
        for (unsigned int y = 0; y < windowSize.y / scale; y += tileSize)
        {
            const auto gameObject = new GameObject();
            const auto sprite = gameObject->AddComponent<SpriteComponent>();
            sprite->SetTexture(*this->_pGrassTexture);
            gameObject->setPosition(sf::Vector2f(static_cast<float>(x * scale), static_cast<float>(y * scale)));
            gameObject->setScale(sf::Vector2f(scale, scale));
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

void GameScene::Dispose()
{
    Scene::Dispose();
}
