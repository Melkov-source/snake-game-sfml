#include "Application.h"

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

    const sf::Vector2u window_size = sf::Vector2u{1280, 720 - 50};

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

    const auto windowSize = Application::GetWindowSize();
    constexpr auto flags =
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
    const auto imGuiSize = ImVec2(static_cast<float>(windowSize.x), static_cast<float>(70));

    ImGui::SetNextWindowPos(ImVec2(0, windowSize.y - 70));
    ImGui::Begin("Game Menu", nullptr, flags);
    ImGui::SetWindowSize(imGuiSize);

    if (ImGui::Button("Menu", ImVec2(100, 50)))
    {
        SceneManager::LoadScene<MenuScene>();
    }

    ImGui::BeginGroup();

    ImGui::SameLine();

    for (std::size_t i = 0; i < 5; i++)
    {
        ImGui::Text("Task: 1");
        ImGui::SameLine();
    }

    ImGui::EndGroup();

    ImGui::End();
}

void GameScene::Render(sf::RenderTarget &renderTarget)
{
    Scene::Render(renderTarget);
}
