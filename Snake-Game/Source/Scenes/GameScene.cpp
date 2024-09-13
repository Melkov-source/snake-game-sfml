#include "GameScene.h"
#include "MenuScene.h"

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

    const sf::Vector2u window_size = sf::Vector2u {1280, 720};

    _map = new Map();
    _snake = new Snake();

    _map->Initialize(scale, window_size);

    _snake->setScale(scale);

    Debug::Logger::Log("Game: Loaded");

    Scene::Initialize();
}

void GameScene::Update(float deltaTime)
{
    Scene::Update(deltaTime);

    ImGui::Begin("Game", nullptr, ImGuiWindowFlags_NoTitleBar);
    _fpsCounter.DrawFpsText(deltaTime);

    if(ImGui::Button("Menu"))
    {
        SceneManager::LoadScene<MenuScene>();
    }
    
    ImGui::End();
}

void GameScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}
