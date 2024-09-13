#include "GameObject.h"

#include "../Debug/Logger.h"
#include "Scenes/SceneManager.h"

GameObject::GameObject(const std::string& name) : Name(name)
{
    const auto scene = SceneManager::GetCurrentScene();

    if(scene != nullptr)
    {
        scene->AddGameObject(*this);
    }
}

GameObject::~GameObject()
{
    for (const auto component : this->_components)
    {
        delete component;
    }
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
                Debug::Logger::Warning("Component for render is nullptr!");
                continue;
            }
            
            component->Render(renderTarget);
        }
    }
}

template <typename TComponent>
TComponent* GameObject::AddComponent()
{
    const std::type_info& type = typeid(TComponent);
    const auto isComponent = std::is_base_of_v<Component, TComponent>;

    if (isComponent == false)
    {
        Debug::Logger::Error("$ must be a subclass of Component", type.name());

        return nullptr;
    }

    auto component = std::make_unique<TComponent>(*this);

    if (!component)
    {
        Debug::Logger::Warning("Failed to create component");

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