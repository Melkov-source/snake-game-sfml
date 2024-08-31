#include "LayerRendererManager.h"

void LayerRendererManager::RegisterLayerRenderer(LayerRenderer& layerRenderer)
{
    this->_layersRenderer.emplace(layerRenderer.Order, &layerRenderer);
}

void LayerRendererManager::Render(sf::RenderTarget& renderTarget)
{
    for (const auto& [order, layer] : _layersRenderer)
    {
        layer->Draw(renderTarget);
    }
}



