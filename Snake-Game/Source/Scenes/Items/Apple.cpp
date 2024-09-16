#include "Apple.h"

Apple::Apple() : Item("Apple")
{
    _textureAtlas = AssetsManager::LoadTexture("Assets/textures/game-atlass.png");

    Sprite->SetTexture(*_textureAtlas);
    Sprite->SetTextureRect(APPLE);
}

Apple::~Apple()
{
    
}

void Apple::Use()
{
}
