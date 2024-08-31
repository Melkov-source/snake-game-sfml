#include "../../include/core/scene.h"

namespace Engine
{
    void Scene::draw(sf::RenderTarget& target) const
    {
        for (const auto child : this->children_)
        {
            child->draw(target, nullptr);
        }
    }
}
