#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "../GameObject.h"

class Scene
{
public:
    std::string Name;

    explicit Scene(std::string name);
    virtual ~Scene();

    void AddGameObject(GameObject& gameObject);

    virtual void Initialize();
        
    virtual void Update(const float deltaTime);
    virtual void Render(sf::RenderTarget& renderTarget);
    virtual void Dispose();

private:
    std::vector<GameObject*> _gameObjects;
};

#endif
