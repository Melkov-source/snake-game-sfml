#pragma once

#include <optional>

#include "SFML/Graphics.hpp"

class GameObject
{
public:
    virtual ~GameObject() = default;
    void draw(sf::RenderTarget& target, const std::optional<sf::Transform&> parent_transform) const;

protected:
    virtual void on_draw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

    sf::Transform transform_;
    std::vector<GameObject*> children_;
};
