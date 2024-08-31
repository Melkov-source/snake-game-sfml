#include "Scene.h"

Scene::Scene(std::string name) : Name(name)
{
}

void Scene::AddGameObject(GameObject& gameObject)
{
    this->_gameObjects.push_back(&gameObject);
}

void Scene::Update(const float deltaTime)
{
    for (auto gameObject : this->_gameObjects)
    {
        gameObject->Update(deltaTime);
    }
}

void Scene::Render(sf::RenderTarget& renderTarget)
{
    for (auto gameObject : this->_gameObjects)
    {
        gameObject->Render(renderTarget);
    }
}

void Scene::Dispose()
{
    for (const auto gameObject : this->_gameObjects)
    {
        gameObject->Dispose();
        delete gameObject;
    }
}
