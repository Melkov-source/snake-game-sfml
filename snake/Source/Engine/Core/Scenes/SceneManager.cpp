#include "SceneManager.h"

#include <iostream>
#include <utility>

template<typename TScene>
void SceneManager::LoadScene()
{
    if(this->_scenes.empty() == false)
    {
        const auto currentScene = _scenes.top();

        this->_deleteScenes.push_back(currentScene);
    }
    
    const auto isScene = std::is_base_of_v<Scene, TScene>;
    static_assert(isScene, "TScene no subclass for Scene");

    auto upScene = std::make_unique<TScene>();

    if(!upScene)
    {
        std::cerr << "Failed to create scene\n";
        return;
    }

    TScene* pScene = upScene.get();
    upScene.release();

    Scene* result = std::move(pScene);

    this->_scenes.push(result);

    result->Initialize();
}

Scene* SceneManager::GetCurrentScene() const
{
    return this->_scenes.top();
}

void SceneManager::Update(const float deltaTime)
{
    if(this->_scenes.empty())
    {
        return;
    }

    const auto currentScene = this->_scenes.top();

    currentScene->Update(deltaTime);

    for (const auto scene : this->_deleteScenes)
    {
        delete scene;
    }

    this->_deleteScenes.clear();
}

void SceneManager::Render(sf::RenderTarget& renderTarget) const
{
    if(this->_scenes.empty())
    {
        return;
    }

    const auto currentScene = this->_scenes.top();
    
    currentScene->Render(renderTarget);
}
