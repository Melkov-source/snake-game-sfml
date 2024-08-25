#include "../../include/states/game-state.h"

GameState::GameState(sf::RenderWindow* render_window) : StateBase(render_window)
{
    
}


GameState::~GameState()
{
}

void GameState::update(const float delta_time)
{
    std::cout << "state.game.update: " << delta_time << '\n';
}

void GameState::render()
{
    ImGui::Begin("Game");
    if(ImGui::Button("Quit"))
    {
        exit();
    }
    ImGui::End(); 
}
