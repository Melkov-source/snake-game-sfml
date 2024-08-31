#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include "Components/Component.h"
#include <vector>

class GameObject
{
public:
    std::string Name;

    void AddComponent(Component& component);

    void Start();
    void Update(float deltaTime);
    void Render(sf::RenderTarget& renderTarget);
    void Dispose();

private:
    std::vector<Component*> _components;
};

#endif

