#pragma once

#include "../../../Engine/Core/GameObject.h"
#include "../../../Engine/Core/Assets/AssetsManager.h"

const sf::IntRect SNAKE_HEAD { 0,0,64,64 };
const sf::IntRect SNAKE_BODY { 64,0,64,64 };

class SnakeElement: public GameObject
{
public:
    enum SNAKE_ELEMENT
    {
        HEAD = 0,
        BODY = 1
    };
    
    SnakeElement(const sf::Texture& texture, SNAKE_ELEMENT type);
    ~SnakeElement() override;
private:
    SpriteComponent* _sprite;
    LayerComponent* _layer;
};

