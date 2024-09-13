#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <vector>

#include "Scene.h"


class SceneManager
{
public:
    static Scene* GetCurrentScene()
    {
        return _scenes.top();
    }

    template<typename TScene>
    static void LoadScene()
    {
        if (_scenes.empty() == false)
        {
            const auto currentScene = _scenes.top();

            _deleteScenes.push_back(currentScene);
        }

        const auto isScene = std::is_base_of_v<Scene, TScene>;
        static_assert(isScene, "TScene no subclass for Scene");

        auto upScene = std::make_unique<TScene>();

        if (!upScene)
        {
            std::cerr << "Failed to create scene\n";
            return;
        }

        TScene* pScene = upScene.get();
        upScene.release();

        Scene* result = std::move(pScene);

        _scenes.push(result);

        result->Initialize();
    }

    static void Update(float deltaTime)
    {
        if(_scenes.empty())
        {
            return;
        }

        const auto currentScene = _scenes.top();

        currentScene->Update(deltaTime);

        for (const auto scene : _deleteScenes)
        {
            delete scene;
        }

        _deleteScenes.clear();
    }
    
    static void Render(sf::RenderTarget& renderTarget)
    {
        if(_scenes.empty())
        {
            return;
        }

        const auto currentScene = _scenes.top();
    
        currentScene->Render(renderTarget);
    }

private:
    inline static std::stack<Scene*> _scenes;
    inline static std::vector<Scene*> _deleteScenes;
};