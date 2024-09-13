#pragma once
#include "Component.h"

class LayerComponent final : public Component
{
public:
    int Order;

    explicit LayerComponent(GameObject& gameObject);
    ~LayerComponent() override;
    
    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
};
