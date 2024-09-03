#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
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

    void Update(float deltaTime) const;
    void Render(sf::RenderTarget& renderTarget) const;

private:
    Scene* _currentScene = nullptr;
};

template void SceneManager::LoadScene<MenuScene>();
template void SceneManager::LoadScene<GameScene>();
#endif
