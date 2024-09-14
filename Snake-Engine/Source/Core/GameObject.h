#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Core/Components/Component.h"
#include "Core/Components/LayerComponent.h" 
#include "Core/Components/SpriteComponent.h"

#include "Debug/Logger.h"

class GameObject : public sf::Transformable
{
  public:
    std::string Name;

    GameObject(const std::string &name);
    virtual ~GameObject();

    virtual void Start();
    virtual void Update(const float deltaTime);
    void Render(sf::RenderTarget &renderTarget);

    template <typename TComponent> void AddComponent(TComponent *component)
    {
        _components.push_back(component);
    }

    template <typename TComponent> TComponent *GetComponent()
    {
        for (const auto &component : this->_components)
        {
            if (typeid(*component) == typeid(TComponent))
            {
                return static_cast<TComponent *>(component);
            }
        }

        return nullptr;
    }

  private:
    std::vector<Component *> _components;
};

#endif
