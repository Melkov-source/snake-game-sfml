#include "Component.h"

#include <iostream>

Component::Component(GameObject& gameObject) : _gameObject(&gameObject)
{
}

Component::~Component()
{
}

void Component::Update(float deltaTime)
{
    std::cout << "update" << "\n";
}
void Component::Render(sf::RenderTarget& renderTarget)
{
}
void Component::Dispose()
{
}