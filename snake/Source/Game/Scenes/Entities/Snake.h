#pragma once

#include "../../../Engine/Core/GameObject.h"
#include "SnakeElement.h"

class Snake final : public GameObject
{
public:
    Snake();
    ~Snake() override;

    void Start() override;
    void Update(const float deltaTime) override;

    void SetSpeed(float speed);
    float GetSpeed();

private:
    sf::Texture* _snakeTexture;
    std::vector<SnakeElement*> _elements;

    SnakeElement* CreateSnakeElement(SnakeElement::SNAKE_ELEMENT type);

    float _speed;
    float _updateTimer; 
    float _updateInterval;
};

