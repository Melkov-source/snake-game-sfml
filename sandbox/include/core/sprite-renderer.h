#pragma once
#include "component.h"
#include "game-object.h"

namespace Engine
{
    class SpriteRenderer final : public Component
    {
    public:
        SpriteRenderer();
        ~SpriteRenderer();
    private:
        void on_draw(sf::RenderTarget& target, const sf::Transform& transform) const;

        sf::Sprite sprite_;
    };
}
