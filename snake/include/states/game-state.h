#pragma once
#include "state-base.h"

class GameState : public StateBase
{
public:
    explicit GameState(sf::RenderWindow* render_window);
    virtual ~GameState() override;
    
    void update(const float delta_time) override;
    void render() override;
};
