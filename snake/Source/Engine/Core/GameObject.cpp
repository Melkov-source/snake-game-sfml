#include "GameObject.h"

void GameObject::AddComponent(Component& component)
{
    this->_components.push_back(&component);
}

void GameObject::Start()
{
}

void GameObject::Update(float deltaTime)
{
    for (const auto component : _components)
    {
        component->Update(deltaTime);
    }
}

void GameObject::Render(sf::RenderTarget& renderTarget)
{
    for (const auto component : _components)
    {
        component->Render(renderTarget);
    }
}

void GameObject::Dispose()
{
    for (const auto component : _components)
    {
        component->Dispose();

        delete component;
    }
}
