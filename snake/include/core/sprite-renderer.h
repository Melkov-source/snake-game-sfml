#pragma once
#include "game-object.h"

class SpriteRenderer final : public GameObject
{
    void on_draw(sf::RenderTarget& target, const sf::Transform& transform) const override;

    sf::Sprite sprite_;
};
