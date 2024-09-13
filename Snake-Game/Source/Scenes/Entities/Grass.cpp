#include "Grass.h"

#include "../../../Engine/Core/Assets/AssetsManager.h"

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

    this->_textureAtlas = AssetsManager::LoadTexture("assets/textures/game-atlass.png");

    this->_sprite->SetTexture(*this->_textureAtlas);

    this->SetState(NORMAL);
    
    GameObject::Start();
}

void Grass::Update(const float deltaTime)
{
    GameObject::Update(deltaTime);
}

void Grass::SetState(STATE state)
{
    this->_currentState = state;

    switch (state)
    {
        case NORMAL:
            this->_sprite->SetTextureRect(GRASS_DEFAULT);
            break;
        case TRAMPLED:
            this->_sprite->SetTextureRect(GRASS_TRAMPLED);
            break;
    }
}

Grass::STATE Grass::GetState() const
{
    return this->_currentState;
}
