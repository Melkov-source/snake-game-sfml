#pragma once
#include "SFML/Graphics/RenderTarget.hpp"

class LayerRenderer
{
public:
    int Order;

    void Draw(sf::RenderTarget& renderTarget) const;
};
