#pragma once
#include "../Engine/Core/GameObject.h"

class Player : public GameObject
{
public:
    void Start() override;
    void Update(float deltaTime) override;
    void Dispose() override;
};
