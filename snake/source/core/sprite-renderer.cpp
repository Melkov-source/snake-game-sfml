#include "../../include/core/sprite-renderer.h"

void SpriteRenderer::on_draw(sf::RenderTarget& target, const sf::Transform& transform) const
{
    target.draw(this->sprite_, transform);
}
