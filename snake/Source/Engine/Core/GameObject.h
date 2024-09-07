#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Components/Component.h"
#include "Components/LayerComponent.h"
#include "Components/SpriteComponent.h"

class GameObject : public sf::Transformable
{
public:
	std::string Name;

    GameObject();
    virtual ~GameObject();

    template <typename TComponent>
    TComponent* AddComponent();

    template<typename TComponent>
    TComponent* GetComponent();

    virtual void Start();
    virtual void Update(const float deltaTime);
    void Render(sf::RenderTarget& renderTarget);
private:
    std::vector<Component*> _components;
};

template SpriteComponent* GameObject::AddComponent<SpriteComponent>();
template LayerComponent* GameObject::AddComponent<LayerComponent>();

template SpriteComponent* GameObject::GetComponent<SpriteComponent>();
template LayerComponent* GameObject::GetComponent<LayerComponent>();

#endif

