#pragma once
#include "Component.h"

class SpriteComponent final : public Component
{
public:
    explicit SpriteComponent(GameObject& gameObject);
    ~SpriteComponent() override;

    void SetTexture(const sf::Texture& texture);
    void SetColor(const sf::Color& color);

    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& renderTarget) override;
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
};
