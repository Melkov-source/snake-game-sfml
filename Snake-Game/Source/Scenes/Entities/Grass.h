#pragma once
#include "../../../Engine/Core/GameObject.h"

const sf::IntRect GRASS_DEFAULT { 0,0,64,64 };
const sf::IntRect GRASS_TRAMPLED { 0,64,64,64 };

class Grass final : public GameObject
{
public:
    enum STATE
    {
        NORMAL = 0,
        TRAMPLED = 1
    };

    Grass();
    ~Grass() override;
    
    void Start() override;
    void Update(const float deltaTime) override;

    void SetState(STATE state);
    STATE GetState() const;

private:
    SpriteComponent* _sprite;
    LayerComponent* _layer;

    sf::Texture* _textureAtlas;

    STATE _currentState;
};
