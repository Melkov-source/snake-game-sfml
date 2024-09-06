#pragma once
#include "../../Engine/Core/GameObject.h"

class Grass final : public GameObject
{
public:
    Grass();
    ~Grass() override;
    
    void Start() override;
    void Update(const float deltaTime) override;

private:
    SpriteComponent* _sprite;
    LayerComponent* _layer;
};
