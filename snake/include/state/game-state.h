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
        bool is_render_logger_box_{};
        int* current_debug_priority_index_;

        void render_gui_box_state();
        void render_gui_box_logger() const;
    }; 
}

