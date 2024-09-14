#include "Grass.h"

Grass::Grass() : GameObject("Grass")
{
    this->_sprite = new SpriteComponent(*this);

    AddComponent(this->_sprite);

    this->_layer = new LayerComponent(*this);

    AddComponent(this->_layer);
}

Grass::~Grass()
{
}

void Grass::Start()
{
    this->_layer->Order = 0;

    this->_textureAtlas = AssetsManager::LoadTexture("Assets/textures/game-atlass.png");

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
