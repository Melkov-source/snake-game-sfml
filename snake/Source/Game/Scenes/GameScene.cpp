#include "GameScene.h"

#include "Entities/Grass.h"
#include "../Application.h"
#include "Entities/Snake.h"

GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    Debug::Logger::Log("Game: Disposed");
}

void GameScene::Initialize()
{
    constexpr unsigned int tileSize = 64;
    const sf::Vector2u windowSize = Application::Core->GetWindowSize();

    constexpr float scaleFactor = 0.4f;

    const auto scale = sf::Vector2f(scaleFactor, scaleFactor);

    for (unsigned int x = 0; x < windowSize.x / scaleFactor; x += tileSize)
    {
        for (unsigned int y = 0; y < windowSize.y / scaleFactor; y += tileSize)
        {
            const auto grass = new Grass();
            
            grass->setPosition(sf::Vector2f(x * scaleFactor, y * scaleFactor));
            grass->setScale(scale);
        }
    }

    this->_snake = new Snake();

    this->_snake->setScale(scale);
    
    Scene::Initialize();

    Debug::Logger::Log("Game: Loaded");
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

    if(ImGui::Button("Add speed"))
    {
        const auto new_speed = this->_snake->GetSpeed() - 0.05f;
        
        this->_snake->SetSpeed(new_speed);
    }

    if(ImGui::Button("Add mass"))
    {
        _snake->AddMass(1);
    }
    
    ImGui::End();
}

void GameScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}
