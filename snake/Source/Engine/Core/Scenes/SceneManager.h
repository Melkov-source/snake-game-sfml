#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <string>
#include "Scene.h"
#include <map>

class SceneManager
{
public:
    Scene* CreateScene(const std::string& sceneName);
    Scene* GetCurrentScene() const;
    Scene* GetSceneByName(const std::string& nameScene);

    void SetScene(const std::string& nameScene);

    void Update(float deltaTime) const;
    void Render(sf::RenderTarget& renderTarget) const;

private:
    std::map<std::string, Scene*> _scenes;
    Scene* _currentScene = nullptr;
};

#endif
