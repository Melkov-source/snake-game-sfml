#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include "Components/Component.h"
#include <vector>

class GameObject
{
public:
    virtual ~GameObject();
    std::string Name;

    void AddComponent(Component& component);

    virtual void Start();
    virtual void Update(float deltaTime);
    void Render(sf::RenderTarget& renderTarget);
    virtual void Dispose();

private:
    std::vector<Component*> _components;
};

#endif

