#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include <stack>
#include <vector>

#include "SFML/Graphics/RenderTarget.hpp"

#include "../../../Game/Scenes/MenuScene.h"
#include "../../../Game/Scenes/GameScene.h"

class Scene;

class SceneManager
{
public:
    Scene* GetCurrentScene() const;

    template<typename TScene>
    void LoadScene();

    void Update(float deltaTime);
    void Render(sf::RenderTarget& renderTarget) const;

private:
    std::stack<Scene*> _scenes;
    std::vector<Scene*> _deleteScenes;
};

template void SceneManager::LoadScene<MenuScene>();
template void SceneManager::LoadScene<GameScene>();
#endif
