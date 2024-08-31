#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "../GameObject.h"

class Scene
{
public:
    std::string Name;

    explicit Scene(std::string name);

    void AddGameObject(GameObject& gameObject);
        
    void Update(const float deltaTime);
    void Render(sf::RenderTarget& renderTarget);
    void Dispose();

private:
    std::vector<GameObject*> _gameObjects;
};

#endif
