#ifndef SCENE_H
#define SCENE_H

#include "Core/GameObject.h"

class Scene
{
public:
    Scene();
    virtual ~Scene();
    
    virtual void Initialize();
    virtual void Update(float deltaTime);
    virtual void Render(sf::RenderTarget& renderTarget);

    void AddGameObject(GameObject& gameObject);
private:
    std::vector<GameObject*> _gameObjects;
};

#endif
