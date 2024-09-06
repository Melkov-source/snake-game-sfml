#include "Component.h"

Component::Component(GameObject& gameObject) : _gameObject(&gameObject)
{
}

Component::~Component()
{
}

void Component::Update(float deltaTime)
{
}

void Component::Render(sf::RenderTarget& renderTarget)
{
}
