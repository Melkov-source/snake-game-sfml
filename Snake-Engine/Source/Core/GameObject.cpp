#include "GameObject.h"
#include "Core/Scenes/SceneManager.h"

GameObject::GameObject(const std::string &name) : Name(name)
{
    const auto scene = SceneManager::GetCurrentScene();

    if (scene != nullptr)
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
    for (const auto &component : _components)
    {
        component->Update(deltaTime);
    }
}

void GameObject::Render(sf::RenderTarget &renderTarget)
{
    if (this->_components.empty() == false)
    {
        for (const auto &component : this->_components)
        {
            if (!component)
            {
                Debug::Logger::Warning("Component for render is nullptr!");
                continue;
            }

            component->Render(renderTarget);
        }
    }
}