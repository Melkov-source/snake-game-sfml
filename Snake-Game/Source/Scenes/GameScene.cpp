#include "GameScene.h"

#include "../Game.cpp"
#include "Entities/Map.h"
#include "Entities/Snake.h"


GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    delete _map;
    Debug::Logger::Log("Game: Disposed");
}

void GameScene::Initialize()
{
    const auto scaleFactor = 0.4f;
    const auto scale = sf::Vector2f(scaleFactor, scaleFactor);

    const sf::Vector2u window_size = Application::Core->GetWindowSize();

    _map = new Map();
    _snake = new Snake();

    _map->Initialize(scale, window_size);

    _snake->setScale(scale);
    
    Scene::Initialize();
    
    const auto position = _map->GetRandomPosition();
    _snake->SetPositionHead(position);

    Debug::Logger::Log("Game: Loaded");
}

void GameScene::Update(float deltaTime)
{
    Scene::Update(deltaTime);

    ImGui::Begin("Game", nullptr, ImGuiWindowFlags_NoTitleBar);
    _fpsCounter.DrawFpsText(deltaTime);

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
