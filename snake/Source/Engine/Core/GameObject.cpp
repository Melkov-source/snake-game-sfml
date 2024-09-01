#include "GameObject.h"

#include <iostream>
GameObject::~GameObject()
{
}
void GameObject::AddComponent(Component& component)
template <typename TComponent>
TComponent* GameObject::AddComponent()
{
    const auto isComponent = std::is_base_of_v<Component, TComponent>;
    static_assert(isComponent, "TComponent must be a subclass of Component");

    auto component = std::make_unique<TComponent>(*this);
    
    if (!component)
    {
        std::cerr << "Failed to create component\n";
        return nullptr;
    }

    TComponent* componentPtr = component.get();
    component.release();

    const auto result = std::move(componentPtr);
    
    _components.push_back(result);

    return result;
}
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
