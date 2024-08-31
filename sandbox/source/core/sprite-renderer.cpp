#include "../../include/core/sprite-renderer.h"

namespace Engine
{
    SpriteRenderer::SpriteRenderer()
    {
        this->name = "sprite_renderer";
    }

    SpriteRenderer::~SpriteRenderer()
    {
    }

    void SpriteRenderer::on_draw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(this->sprite_, transform);
    }
}
