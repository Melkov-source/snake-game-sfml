#pragma once
#include "../Engine/Core/GameObject.h"

class Player : public GameObject
{
public:
    void Start() override;
    void Update(const float deltaTime) override;

private:
    float _timeElapsed;
};
