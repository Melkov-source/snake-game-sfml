#include "Scene.h"

namespace Core::Scenes
{
    Scene::Scene(std::string name) : Name(std::move(name))
    {
    }

    void Scene::Update(const float deltaTime)
    {
    }

    void Scene::Render(const sf::RenderTarget& renderTarget)
    {
    }

    void Scene::Dispose()
    {
    }
}
