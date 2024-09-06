#include "MenuScene.h"

#include "GameScene.h"
#include "imgui.h"
#include "../Application.h"

MenuScene::~MenuScene()
{
    
}

void MenuScene::Initialize()
{
    Scene::Initialize();
}

void MenuScene::Update(const float deltaTime)
{
    const auto windowSize = Application::Core->GetWindowSize();
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
    if (ImGui::Button("PLAY", ImVec2(300, 50)))
    {
        Application::Core->Scene->LoadScene<GameScene>();
    }

    ImGui::SetCursorPos({imGuiSize.x / 2 - 150, imGuiSize.y / 2 + 60 - 25});
    if (ImGui::Button("EXIT", ImVec2(300, 50)))
    {
        Application::Close();
    }

    ImGui::End();
    
    Scene::Update(deltaTime);
}

void MenuScene::Render(sf::RenderTarget& renderTarget)
{
    Scene::Render(renderTarget);
}
