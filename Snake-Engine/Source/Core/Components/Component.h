#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML/Graphics.hpp"

class GameObject;

class Component
{
  public:
    std::string Name;
    bool IsEnable{true};

    explicit Component(GameObject &gameObject);
    virtual ~Component();

    virtual void Update(float deltaTime);
    virtual void Render(sf::RenderTarget &renderTarget);

  protected:
    GameObject *_gameObject;
};

#endif // !COMPONENT_H
