#pragma once
#include "game-object.h"
#include "SFML/Graphics.hpp"

class Scene
{
public:
    void draw(sf::RenderTarget& target) const;

private:
    std::vector<GameObject*> children_;
};
