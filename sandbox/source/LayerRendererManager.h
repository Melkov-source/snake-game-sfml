#pragma once
#include <map>

#include "LayerRenderer.h"

class LayerRendererManager
{
public:
    void RegisterLayerRenderer(LayerRenderer& layerRenderer);
    void Render(sf::RenderTarget& renderTarget);

private:
    std::multimap<int, LayerRenderer*> _layersRenderer;
};

