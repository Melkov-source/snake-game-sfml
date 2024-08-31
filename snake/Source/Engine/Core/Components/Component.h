#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML/Graphics.hpp"

class GameObject;

class Component
{
public:
	GameObject* GameObject = nullptr;

	void Update(float deltaTime);
	void Render(sf::RenderTarget& renderTarget);

	void Dispose();
};

#endif // !COMPONENT_H

