#include "Player.h"

#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"
#include "../Engine/Core/Assets/AssetsManager.h"
#include "../Engine/Core/Components/SpriteComponent.h"

void Player::Start()
{
    const auto grassTexture = AssetsManager::LoadTexture("assets/textures/game-atlass.png", {64, 64, 64, 64});
    
    const auto spriteRenderer = this->AddComponent<SpriteComponent>();

    spriteRenderer->SetTexture(*grassTexture);

    std::cout << spriteRenderer->Name << " " << this->Name << "\n";
}

void Player::Update(const float deltaTime)
{
    auto spriteComponent = this->GetComponent<SpriteComponent>();
    
    ImGui::Begin("Debug Player");

    if(ImGui::Button("Switch texture"))
    {
        const auto grassTexture = AssetsManager::LoadTexture("assets/textures/game-atlass.png", {0, 0, 64, 64});

        spriteComponent->SetTexture(*grassTexture);
    }

    ImGui::BeginGroup();

    const auto layer = GetComponent<LayerComponent>();
    
    if(ImGui::Button("-"))
    {
        layer->Order--;
    }
    
    ImGui::SameLine();
    ImGui::Text("Order: %i", layer->Order);
    ImGui::SameLine();

    if(ImGui::Button("+"))
    {
        layer->Order++;
    }
    
    ImGui::EndGroup();

    if(ImGui::Button("Reset position"))
    {
       this->setPosition(0,0);
    }
    
    ImGui::End();
    
    GameObject::Update(deltaTime);

    move(100.0f * deltaTime, 0.0f);
    
    if (spriteComponent)
    {
        _timeElapsed += deltaTime;
        if (_timeElapsed >= 0.5f)
        {
            sf::Color newColor(rand() % 256, rand() % 256, rand() % 256);
            spriteComponent->SetColor(newColor);
            _timeElapsed = 0.0f;
        }
    }
}
