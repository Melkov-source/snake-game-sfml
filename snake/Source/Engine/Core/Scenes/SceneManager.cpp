#include "SceneManager.h"

#include <utility>

Scene* SceneManager::CreateScene(const std::string& sceneName)
{
    const auto scene = new Scene(sceneName);

    if(this->_scenes.count(sceneName))
    {
        return nullptr;
    }

    this->_scenes[sceneName] = scene;

    return scene;
}

Scene* SceneManager::GetCurrentScene() const
{
    return this->_currentScene;
}

Scene* SceneManager::GetSceneByName(const std::string& nameScene)
{
    if(this->_scenes.count(nameScene) == false)
    {
        return nullptr;
    }

    return this->_scenes[nameScene];
}
    
void SceneManager::Update(const float deltaTime) const
{
    if(this->_currentScene != nullptr)
    {
        _currentScene->Update(deltaTime);
    }
}

void SceneManager::Render(sf::RenderTarget& renderTarget) const
{
    if(this->_currentScene != nullptr)
    {
        _currentScene->Render(renderTarget);
    }
}
