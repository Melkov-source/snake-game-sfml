#include "LayerComponent.h"

#include "../GameObject.h"

LayerComponent::LayerComponent(GameObject& gameObject) : Component(gameObject), Order(0)
{
}

LayerComponent::~LayerComponent()
= default;

void LayerComponent::Update(float deltaTime)
{
    Component::Update(deltaTime);
}

void LayerComponent::Render(sf::RenderTarget& renderTarget)
{
    Component::Render(renderTarget);
}