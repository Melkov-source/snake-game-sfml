#ifndef SCENE_H
#define SCENE_H

#include "../GameObject.h"

class Scene
{
public:
    Scene();
    virtual ~Scene();

    void AddGameObject(GameObject& gameObject);

    virtual void Load();
    virtual void Initialize();
        
    virtual void Update(float deltaTime);
    virtual void Render(sf::RenderTarget& renderTarget);
    virtual void Dispose();

private:
    std::vector<GameObject*> _gameObjects;
};

#endif
