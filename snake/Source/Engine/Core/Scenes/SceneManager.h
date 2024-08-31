#pragma once
#include "Scene.h"

namespace Core::Scenes
{
    class SceneManager
    {
    public:
        Scene* CreateScene(const std::string& sceneName);
        Scene* GetCurrentScene() const;
        Scene* GetSceneByName(const std::string& nameScene);

        void Update(float deltaTime) const;
        void Render(sf::RenderTarget& renderTarget) const;

    private:
        std::map<std::string, Scene*> _scenes;
        Scene* _currentScene;
    };
}

