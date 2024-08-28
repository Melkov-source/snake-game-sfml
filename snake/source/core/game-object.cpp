#include "../../include/core/game-object.h"

#include <optional>

void GameObject::draw(sf::RenderTarget& target, const std::optional<sf::Transform&> parent_transform) const
{
    sf::Transform combined_transform = this->transform_;

    if(parent_transform)
    {
        combined_transform *= parent_transform.value();
    }

    this->on_draw(target, combined_transform);
    
    for (const auto child : this->children_)
    {
        child->draw(target, combined_transform);
    }
}
