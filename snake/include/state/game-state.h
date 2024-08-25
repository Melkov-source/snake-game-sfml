#pragma once
#include "state-base.h"

namespace state
{
    class GameState final : public StateBase
    {
    public:
        explicit GameState(sf::RenderWindow* render_window);
        ~GameState() override;
    
        void update(const float delta_time) override;
        void render() override;
        void dispose() override;

    private:
        float delta_time_{};
    }; 
}

