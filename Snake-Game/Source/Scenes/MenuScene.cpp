#include "Application.h"

#include "MenuScene.h"
#include "GameScene.h"

MenuScene::~MenuScene()
{
    Debug::Logger::Log("Menu: Disposed");
}

void MenuScene::Initialize()
{
    Scene::Initialize();

    Debug::Logger::Log("Menu: Loaded");
}

void MenuScene::Update(const float deltaTime)
{
    const auto windowSize = Application::GetWindowSize();

    constexpr auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
    const auto imGuiSize = ImVec2
    (
        static_cast<float>(windowSize.x),
        static_cast<float>(windowSize.y)
    );
    
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Game Menu", nullptr, flags);
    ImGui::SetWindowSize(imGuiSize);
    ImGui::SetWindowFontScale(2.0f);

    ImGui::SetWindowFontScale(4.0f);
    ImGui::SetCursorPos({imGuiSize.x / 2 - 75, imGuiSize.y / 2 - 200 - 25});
    ImGui::Text("Snake");
    ImGui::SetWindowFontScale(2.0f);

    ImGui::SetCursorPos({imGuiSize.x / 2 - 150, imGuiSize.y / 2 - 10 - 25});
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.0f, 1.0f));
    if (ImGui::Button("PLAY", ImVec2(300, 50)))
    {
        SceneManager::LoadScene<GameScene>();
    }
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.6f, 0.0f, 0.0f, 1.0f));
    ImGui::SetCursorPos({imGuiSize.x / 2 - 150, imGuiSize.y / 2 + 60 - 25});
    if (ImGui::Button("EXIT", ImVec2(300, 50)))
    {
        Application::Close();
    }
    ImGui::PopStyleColor();

    ImGui::End();
    
    Scene::Update(deltaTime);
}

void MenuScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}