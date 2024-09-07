#include "Scene.h"

#include "../GameObject.h"
#include "../Components/Component.h"
#include "../Components/LayerComponent.h"

Scene::Scene()
= default;

Scene::~Scene()
{
    for (const auto& gameObject : this->_gameObjects)
    {
        delete gameObject;
    }
}

void Scene::AddGameObject(GameObject& gameObject)
{
    this->_gameObjects.push_back(&gameObject);
}

void Scene::Initialize()
{
    for (const auto& gameObject : this->_gameObjects)
    {
        gameObject->Start();
    }
}

void Scene::Update(const float deltaTime)
{
    for (const auto& gameObject : this->_gameObjects)
    {
        gameObject->Update(deltaTime);
    }
}

void Scene::Render(sf::RenderTarget& renderTarget)
{
    std::sort(this->_gameObjects.begin(), this->_gameObjects.end(), [](const auto& obj1, const auto& obj2)
    {
        auto layerComp1 = obj1->GetComponent<LayerComponent>();
        auto layerComp2 = obj2->GetComponent<LayerComponent>();

        int order1 = layerComp1 ? layerComp1->Order : 0;
        int order2 = layerComp2 ? layerComp2->Order : 0;

        return order1 < order2;
    });

    for (const auto& gameObject : this->_gameObjects)
    {
        gameObject->Render(renderTarget);
    }
}
