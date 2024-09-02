#include "Game.h"

#include "Application.h"
#include "Player.h"
#include "Scenes/MenuScene.h"

Game::Game()
{
}

void Game::Start()
{
    new MenuScene();

    Application::EngineApi->SceneManagement->SetScene("Menu");
}
