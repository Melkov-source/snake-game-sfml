#include "SceneManager.h"

#include <iostream>
#include <utility>

bool SceneManager::TryRegisterScene(Scene& scene)
{
    if(this->_scenes.count(scene.Name))
    {
        return false;
    }
    
    this->_scenes[scene.Name] = &scene;

    return true;
}

Scene* SceneManager::CreateScene(const std::string& sceneName)
{
    const auto scene = new Scene(sceneName);

    if(this->TryRegisterScene(*scene))
    {
        return scene;
    }

    return nullptr;
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

void SceneManager::SetScene(const std::string& nameScene)
{
    if(this->_scenes.count(nameScene) == false)
    {
        std::cout << "Not found target scene: " << nameScene << "\n";
        return;
    }

    const auto scene = this->_scenes[nameScene];

    scene->Initialize();

    this->_currentScene = scene;
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
