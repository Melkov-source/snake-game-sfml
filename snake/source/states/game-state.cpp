#include "../../include/states/game-state.h"

GameState::GameState(sf::RenderWindow* render_window) : StateBase(render_window)
{
    
}

void GameState::update(const float delta_time)
{
    std::cout << "state.game.update: " << delta_time << '\n';
}

void GameState::render()
{
    ImGui::Begin("state: game");
    
    if(ImGui::Button("quit"))
    {
        exit();
    }
    
    ImGui::End(); 
}

void GameState::dispose()
{
    std::cout << "state.game.dispose: " << this << "\n";
}
