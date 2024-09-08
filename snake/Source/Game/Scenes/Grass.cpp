#include "Grass.h"

#include "../../Engine/Core/Assets/AssetsManager.h"

Grass::Grass() : GameObject("Grass")
{
    this->_sprite = this->AddComponent<SpriteComponent>();
    this->_layer = this->AddComponent<LayerComponent>();
}

Grass::~Grass()
{
}

void Grass::Start()
{
    this->_layer->Order = 0;

    const auto grassTexture = AssetsManager::LoadTexture("assets/textures/game-atlass.png", {0, 0, 64, 64});

    this->_sprite->SetTexture(*grassTexture);
    
    GameObject::Start();
}

void Grass::Update(const float deltaTime)
{
    GameObject::Update(deltaTime);
}
