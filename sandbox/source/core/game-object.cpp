#include "../../include/core/game-object.h"

#include <optional>

namespace Engine
{
    GameObject::GameObject()
    {
        this->transform = new Transform();
    }

    void GameObject::draw(sf::RenderTarget& target, const sf::Transform* parent_transform) const
    {
        sf::Transform combined_transform = this->transform_;

        if(parent_transform != nullptr)
        {
            combined_transform *= *parent_transform;
        }
   
        this->on_draw(target, combined_transform);
    
        for (const auto child : this->children_)
        {
            child->draw(target, &combined_transform);
        }
    }

    Transform& GameObject::get_transform() const
    {
        return *this->transform;
    }

    void GameObject::on_draw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
    }

    template <typename TComponent>
    TComponent* GameObject::get_component(const std::string name)
    {
        for (const auto component : this->components_)
        {
            if(component->name == name)
            {
                return component;
            }
        }

        return nullptr;
    }
    
    void GameObject::add_component(Component* component)
    {
        this->components_.push_back(component);
    }
}
