#include "../../include/state/game-state.h"

#include "../../include/core/sprite-renderer.h"

namespace state
{
    GameState::GameState(sf::RenderTarget* render_window) : StateBase(render_window)
    {
        this->current_debug_priority_index_ = new int(utils::TRACE_PRIORITY);
        this->assets_manager_ = new assets::AssetsManager();
    }

    GameState::~GameState()
    {
        delete this->current_debug_priority_index_;
        delete this->assets_manager_;
    }

    void GameState::update(const float delta_time)
    {
        this->delta_time_ = delta_time;
    }

    void GameState::render()
    {
        this->render_gui_box_state();
        this->render_gui_box_logger();

        if (this->sprites_.empty() == false)
        {
            for (const auto sprite : this->sprites_)
            {
                this->render_window_->draw(*sprite);
            }
        }
    }

    void GameState::dispose()
    {
        std::cout << "state.game.dispose: " << this << "\n";
    }

    void GameState::render_gui_box_state()
    {
        ImGui::SetNextWindowPos(ImVec2(200, this->render_window_->getSize().y - 200)); // Устанавливаем позицию в левый верхний угол
        ImGui::SetNextWindowSize(ImVec2(this->render_window_->getSize().x - 200, 200));

        ImGui::Begin("Logger", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

          ImGui::Text("Delta Time: %f", this->delta_time_);

        ImGui::End();
        
        ImGui::SetNextWindowPos(ImVec2(0, 0)); // Устанавливаем позицию в левый верхний угол
        ImGui::SetNextWindowSize(ImVec2(200, this->render_window_->getSize().y));
        // Устанавливаем фиксированную ширину и высоту окна

        ImGui::Begin("state.game", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Delta Time: %f", this->delta_time_);

        if (ImGui::Button("Create prefab"))
        {
            engine::GameObject game_object;

            auto sprite = new engine::SpriteRenderer();

            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);
            game_object.add_component(sprite);

            assets_manager_->create_prefab("prefabs/test.prefab", game_object);
        }

        if (ImGui::Button("Load prefab"))
        {
            assets_manager_->load_prefab("prefabs/test.prefab");
        }

        if(ImGui::Button("Print all files in dir"))
        {
            std::string path = "assets";
            for (const auto & entry : std::filesystem::directory_iterator(path))
            {
                std::cout << entry.path() << std::endl;
            }
              
        }

        if (ImGui::Button("Draw Grass Texture"))
        {
            const auto grass_texture = this->assets_manager_->load_texture("textures/grass.png");

            const auto grass_sprite = new sf::Sprite();

            grass_sprite->setTexture(*grass_texture);

            const sf::Vector2u window_size = this->render_window_->getSize();
            const sf::Vector2u texture_size = grass_texture->getSize();

            const sf::Vector2u center_position =
            {
                0,
                0
            };

            const auto size = this->sprites_.size();
            const unsigned int add_x = texture_size.x * static_cast<unsigned int>(size);

            const float target_x = static_cast<float>(center_position.x + add_x);
            const float target_y = static_cast<float>(center_position.y);

            grass_sprite->setPosition(target_x, target_y);

            auto origin = grass_sprite->getOrigin();

            std::cout << origin.x << origin.y;

            this->sprites_.push_back(grass_sprite);
        }

        if (ImGui::Button("logger.settings"))
        {
            this->is_render_logger_box_ = !this->is_render_logger_box_;
        }

        if (ImGui::Button("state.quit"))
        {
            exit();
        }

        ImGui::End();
    }

    void GameState::render_gui_box_logger() const
    {
        if (this->is_render_logger_box_)
        {
            ImGui::Begin("logger.settings");

            const char* types[] = {
                "Trace",
                "Debug",
                "Info",
                "Warn",
                "Error",
                "Critical",
                "None"
            };

            ImGui::Combo("Log Level", current_debug_priority_index_, types, IM_ARRAYSIZE(types));

            if (utils::get_priority() != *current_debug_priority_index_)
            {
                switch (*this->current_debug_priority_index_)
                {
                    case 0: set_priority(utils::TRACE_PRIORITY);
                        break;
                    case 1: set_priority(utils::DEBUG_PRIORITY);
                        break;
                    case 2: set_priority(utils::INFO_PRIORITY);
                        break;
                    case 3: set_priority(utils::WARN_PRIORITY);
                        break;
                    case 4: set_priority(utils::ERROR_PRIORITY);
                        break;
                    case 5: set_priority(utils::CRITICAL_PRIORITY);
                        break;
                    case 6: set_priority(utils::NONE_PRIORITY);
                        break;
                    default: ;
                }
            }

            if (ImGui::Button("trace")) utils::trace("This test log for trace type message");
            if (ImGui::Button("debug")) utils::debug("This test log for debug type message");
            if (ImGui::Button("info")) utils::info("This test log for info type message");
            if (ImGui::Button("warn")) utils::warn("This test log for warn type message");
            if (ImGui::Button("error")) utils::error("This test log for error type message");
            if (ImGui::Button("critical")) utils::critical("This test log for critical type message");

            ImGui::End();
        }
    }
}
