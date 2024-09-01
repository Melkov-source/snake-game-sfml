#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML/Graphics.hpp"

class GameObject;

class Component
{
public:
	Component(GameObject& gameObject);
	virtual ~Component();
	std::string Name;

	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderTarget& renderTarget);

	virtual void Dispose();

protected:
	GameObject* _gameObject;
};

#endif // !COMPONENT_H

