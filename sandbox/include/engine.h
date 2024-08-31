#pragma once

#include "./state/state-base.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void run();
    void update();
    void render();
    void close();

private:
    sf::RenderWindow* p_render_window_;
    sf::Event event_;

    sf::Clock delta_time_clock_;
    sf::Time delta_time_;

    std::stack<state::StateBase*> states_;

    void initialize();
    void update_states();
    void update_events();
};
