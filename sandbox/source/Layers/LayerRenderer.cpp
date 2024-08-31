#include "LayerRenderer.h"

#include <iostream>

void LayerRenderer::Draw(sf::RenderTarget& renderTarget) const
{
    std::cout << "Layer: " << this->Order << "\n";
}
