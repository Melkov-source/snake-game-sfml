#include "Game.h"

Game::Game(Engine& engine) : _engine(&engine)
{
}

void Game::Start()
{
    const auto menuScene = this->_engine->SceneManagment->CreateScene("Menu");
    
    /*const auto player = new Player();

    menuScene->AddGameObject(*player);*/
}
