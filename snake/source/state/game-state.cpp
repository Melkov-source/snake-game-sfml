#include "../../include/state/game-state.h"

namespace state
{
    GameState::GameState(sf::RenderWindow* render_window) : StateBase(render_window)
    {
    }

    GameState::~GameState()
    {
    }

    void GameState::update(const float delta_time)
    {
        this->delta_time_ = delta_time;
    }

    void GameState::render()
    {
        this->render_gui_box_state();
        this->render_gui_box_logger();
    }

    void GameState::dispose()
    {
        std::cout << "state.game.dispose: " << this << "\n";
    }

    void GameState::render_gui_box_state()
    {
        ImGui::Begin("state: game");

        ImGui::Text("Delta Time: %f", this->delta_time_);

        if (ImGui::Button("logger"))
        {
            this->is_render_logger_box_ = !this->is_render_logger_box_;
        }

        if (ImGui::Button("quit"))
        {
            exit();
        }

        ImGui::End();
    }

    void GameState::render_gui_box_logger() const
    {
        if (this->is_render_logger_box_)
        {
            ImGui::Begin("logger");


            const char* types[] = {
                "Trace",
                "Debug",
                "Info",
                "Warn",
                "Error",
                "Critical"
            };

            static int current_type = 0; // Index for the current log type
            ImGui::Combo("Log Level", &current_type, types, IM_ARRAYSIZE(types));

            // Set the priority based on the selected log level
            switch (current_type)
            {
                case 0: // Trace
                    utils::Logger::set_priority(utils::TRACE_PRIORITY);
                break;
                case 1: // Debug
                    utils::Logger::set_priority(utils::DEBUG_PRIORITY);
                break;
                case 2: // Info
                    utils::Logger::set_priority(utils::INFO_PRIORITY);
                break;
                case 3: // Warn
                    utils::Logger::set_priority(utils::WARN_PRIORITY);
                break;
                case 4: // Error
                    utils::Logger::set_priority(utils::ERROR_PRIORITY);
                break;
                case 5: // Critical
                    utils::Logger::set_priority(utils::CRITICAL_PRIORITY);
                break;
            }

            if (ImGui::Button("trace")) utils::Logger::trace("This test log for trace type message");
            if (ImGui::Button("debug")) utils::Logger::debug("This test log for debug type message");
            if (ImGui::Button("info")) utils::Logger::info("This test log for info type message");
            if (ImGui::Button("warn")) utils::Logger::warn("This test log for warn type message");
            if (ImGui::Button("error")) utils::Logger::error("This test log for error type message");
            if (ImGui::Button("critical")) utils::Logger::critical("This test log for critical type message");

            ImGui::End();
        }
    }
}
