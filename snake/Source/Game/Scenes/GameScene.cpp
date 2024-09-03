#include "GameScene.h"

#include "imgui.h"
#include "../Application.h"

GameScene::~GameScene()
{
    Scene();
}

void GameScene::Load()
{
    Scene::Load();
}

void GameScene::Initialize()
{
    Scene::Initialize();
}

void GameScene::Update(float deltaTime)
{
    ImGui::Begin("Game", nullptr, ImGuiWindowFlags_NoTitleBar);
    ImGui::Text("Scene: Game");

    if(ImGui::Button("Menu"))
    {
        Application::EngineApi->SceneManagement->LoadScene<MenuScene>();
    }
    ImGui::End();
    
    Scene::Update(deltaTime);
}

void GameScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}

void GameScene::Dispose()
{
    Scene::Dispose();
}
