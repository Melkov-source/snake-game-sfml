#include "../../include/state/game-state.h"

state::GameState::GameState(sf::RenderWindow* render_window) : StateBase(render_window)
{
    
}

state::GameState::~GameState()
{
}

void state::GameState::update(const float delta_time)
{
    this->delta_time_ = delta_time;
}

void state::GameState::render()
{
    ImGui::Begin("state: game");
    
    ImGui::Text("Delta Time: %f", this->delta_time_);
    
    if(ImGui::Button("quit"))
    {
        exit();
    }
    
    ImGui::End(); 
}

void state::GameState::dispose()
{
    std::cout << "state.game.dispose: " << this << "\n";
}
