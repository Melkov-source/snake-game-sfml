#include "SceneManager.h"

#include <iostream>
#include <utility>

template<typename TScene>
void SceneManager::LoadScene()
{
    if(this->_currentScene != nullptr)
    {
        this->_currentScene->Dispose();
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

    this->_currentScene = result;

    result->Load();
    result->Initialize();
}

Scene* SceneManager::GetCurrentScene() const
{
    return this->_currentScene;
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
