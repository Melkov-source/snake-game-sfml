#include "Player.h"

#include <iostream>

#include "../Engine/Core/Assets/AssetsManager.h"
#include "../Engine/Core/Components/SpriteComponent.h"

void Player::Start()
{
    const auto grassTexture = AssetsManager::LoadTexture("assets/textures/game-atlass.png", {64, 64, 64, 64});
    
    const auto spriteRenderer = this->AddComponent<SpriteComponent>();

    spriteRenderer->SetTexture(*grassTexture);

    std::cout << spriteRenderer->Name << " " << this->Name << "\n";
}

void Player::Update(float deltaTime)
{
    GameObject::Update(deltaTime);
    
    auto spriteComponent = this->GetComponent<SpriteComponent>();

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

void Player::Dispose()
{
   
}
