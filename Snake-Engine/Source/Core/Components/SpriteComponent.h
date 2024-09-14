#pragma once
#include "Component.h"

class SpriteComponent final : public Component
{
  public:
    explicit SpriteComponent(GameObject &gameObject);
    ~SpriteComponent() override;

    void Update(float deltaTime) override;
    void Render(sf::RenderTarget &renderTarget) override;

    void SetTexture(const sf::Texture &texture);
    void SetTextureRect(const sf::IntRect area);
    void SetColor(const sf::Color &color);

  private:
    sf::Sprite _sprite;
    sf::Texture _texture;
};
