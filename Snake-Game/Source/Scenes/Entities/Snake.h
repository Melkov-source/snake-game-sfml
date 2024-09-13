#pragma once

#include "Core/GameObject.h"
#include "Core/Assets/AssetsManager.h"

const sf::IntRect SNAKE_HEAD { 0,0,64,64 };
const sf::IntRect SNAKE_BODY { 64,0,64,64 };

class Snake final : public GameObject
{
public:
    Snake();
    ~Snake() override;

    void Start() override;
    void Update(const float deltaTime) override;

    void SetSpeed(float speed);
    float GetSpeed();

    void AddMass(int32_t mass);
    void SetPositionHead(const sf::Vector2f& position);

private:
    sf::Texture* _snakeTexture;
    std::vector<GameObject*> _elements;

    float _speed;
    float _updateTimer; 
    float _updateInterval;
    sf::Vector2f _direction;
};

