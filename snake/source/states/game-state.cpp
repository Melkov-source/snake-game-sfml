#include "../../include/states/game-state.h"

GameState::GameState(sf::RenderWindow* render_window) : StateBase(render_window)
{
    
}


GameState::~GameState()
{
}

void GameState::update(const float delta_time)
{
}

void GameState::render()
{
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End(); 
}

void GameState::exit()
{
}
