#include "../include/game.h"

#include "../include/states/game-state.h"

Game::Game()
{
    this->initialize();
}

Game::~Game()
{
    delete this->p_render_window_;

    while (this->states_.empty() == false)
    {
        const auto state = this->states_.top();

        delete state;

        this->states_.pop();
    }
}

void Game::initialize()
{
    std::ifstream window_config("configs/window.ini");

    std::string title = "None";
    sf::VideoMode video_mode(800, 600);
    unsigned int target_frame_rate = 120;
    bool is_vertical_sync = false;

    if (window_config.is_open())
    {
        window_config >> title;
        window_config >> video_mode.width >> video_mode.height;
        window_config >> target_frame_rate;
        window_config >> is_vertical_sync;
    }

    this->p_render_window_ = new sf::RenderWindow(video_mode, title);

    this->p_render_window_->setFramerateLimit(target_frame_rate);
    this->p_render_window_->setVerticalSyncEnabled(is_vertical_sync);

    ImGui::SFML::Init(*this->p_render_window_);

    const auto game_state = new GameState(this->p_render_window_);

    this->states_.push(game_state);
}

void Game::run()
{
    while (this->p_render_window_->isOpen())
    {
        this->update();
        this->render();
    }

    this->shutdown();
}

void Game::update()
{
    this->delta_time_ = this->delta_time_clock_.restart();
    
    this->update_events();
    this->update_states();
    
    ImGui::SFML::Update(*this->p_render_window_, this->delta_time_);
}

void Game::render()
{
    this->p_render_window_->clear();

    if (this->states_.empty() == false)
    {
        StateBase& state = *this->states_.top();
        state.render();
    }

    ImGui::SFML::Render(*this->p_render_window_);

    this->p_render_window_->display();
}

void Game::shutdown()
{
    ImGui::SFML::Shutdown();
}

void Game::update_events()
{
    while (this->p_render_window_->pollEvent(this->event_))
    {
        ImGui::SFML::ProcessEvent(*this->p_render_window_, this->event_);

        switch (this->event_.type)
        {
            case sf::Event::Closed:
                this->p_render_window_->close();
            break;
            default:
                break;
        }
    }
}


void Game::update_states()
{
    if (this->states_.empty())
    {
        this->p_render_window_->close();
        return;
    }

    const auto state = this->states_.top();

    if (state->state_code == state::STATE_EXIT_CODE)
    {
        state->dispose();
        
        delete state;

        this->states_.pop();

        return;
    }

    const float delta_time_seconds = this->delta_time_.asSeconds();

    state->update(delta_time_seconds);
}
