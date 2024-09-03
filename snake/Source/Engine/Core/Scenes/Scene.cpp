#include "Scene.h"

Scene::Scene()
= default;

Scene::~Scene()
= default;

void Scene::AddGameObject(GameObject& gameObject)
{
    this->_gameObjects.push_back(&gameObject);
}

void Scene::Load()
{
}

void Scene::Initialize()
{
    for (const auto gameObject : this->_gameObjects)
    {
        gameObject->Start();
    }
}

void Scene::Update(const float deltaTime)
{
    for (const auto gameObject : this->_gameObjects)
    {
        gameObject->Update(deltaTime);
    }
}

void Scene::Render(sf::RenderTarget& renderTarget)
{
    for (const auto gameObject : this->_gameObjects)
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
