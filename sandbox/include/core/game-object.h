#pragma once

#include "component.h"
#include "../../source/core/Transform.h"
#include "SFML/Graphics.hpp"

namespace Engine
{
    class GameObject
    {
    public:
        Transform* transform;
        GameObject();
        virtual ~GameObject() = default;
        void draw(sf::RenderTarget& target, const sf::Transform* parent_transform) const;

        template<typename TComponent>
        TComponent* get_component(std::string name);
        Transform& get_transform() const;

        void add_component(Component* component);

        sf::Transform transform_;
        std::vector<GameObject*> children_;
        std::vector<Component*> components_;

    protected:
        virtual void on_draw(sf::RenderTarget& target, const sf::Transform& transform) const;

        
    };
}
