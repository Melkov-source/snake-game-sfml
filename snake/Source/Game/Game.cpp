#include "Game.h"

#include "Player.h"

Game::Game(Engine& engine) : _engine(&engine)
{
}

void Game::Start()
{
    const auto menuScene = this->_engine->SceneManagment->CreateScene("Menu");
    
    const auto player = new Player();

    player->Name = "asdasd";

    menuScene->AddGameObject(*player);

    this->_engine->SceneManagment->SetScene(menuScene->Name);
}
