#include "GameObject.h"

#include <iostream>

GameObject::~GameObject()
{
}

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

template <typename TComponent>
TComponent* GameObject::GetComponent()
{
    for (const auto& component : this->_components)
    {
        if (typeid(*component) == typeid(TComponent))
        {
            return static_cast<TComponent*>(component);
        }
    }

    return nullptr;
}

void GameObject::Start()
{
}

void GameObject::Update(const float deltaTime)
{
    for (const auto& component : _components)
    {
        component->Update(deltaTime);
    }
}

void GameObject::Render(sf::RenderTarget& renderTarget)
{
    if(this->_components.empty() == false)
    {
        for (const auto& component : this->_components)
        {
            if(!component)
            {
                std::cout << "component for render is nullptr!\n";
                continue;
            }
            
            component->Render(renderTarget);
        }
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
