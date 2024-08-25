#pragma once
#include "state-base.h"

class GameState final : public StateBase
{
public:
    explicit GameState(sf::RenderWindow* render_window);
    
    void update(const float delta_time) override;
    void render() override;
    void dispose() override;
};
