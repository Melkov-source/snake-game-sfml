#include "../include/game.h"

Game::Game()
{
	this->initialize();
}

Game::~Game()
{
	delete this->p_render_window_;
}

void Game::initialize()
{
	ifstream window_config("configs/window.ini");

	string title = "None";
	VideoMode video_mode(800, 600);
	unsigned int target_frame_rate = 120;
	bool is_vertical_sync = false;

	if (window_config.is_open())
	{
		window_config >> title;
		window_config >> video_mode.width >> video_mode.height;
		window_config >> target_frame_rate;
		window_config >> is_vertical_sync;
	}

	this->p_render_window_ = new RenderWindow(video_mode, title);

	this->p_render_window_->setFramerateLimit(target_frame_rate);
	this->p_render_window_->setVerticalSyncEnabled(is_vertical_sync);

	ImGui::SFML::Init(*this->p_render_window_);
}

void Game::run()
{
	while (this->p_render_window_->isOpen())
	{
		this->update_delta_time();
		this->update();
		this->render();
	}

	this->shutdown();
}

void Game::update_delta_time()
{
	this->delta_time_ = this->delta_time_clock_.restart();
}

void Game::update_events()
{
	while (this->p_render_window_->pollEvent(this->event_))
	{
		ImGui::SFML::ProcessEvent(*this->p_render_window_, this->event_);
		
		switch (this->event_.type)
		{
			case Event::Closed:
				this->p_render_window_->close();
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
	this->update_events();
	ImGui::SFML::Update(*this->p_render_window_, this->delta_time_);

	ImGui::Begin("Hello, world!");
	ImGui::Button("Look at this pretty button");
	ImGui::End();
}

void Game::render()
{
	this->p_render_window_->clear();
	
	ImGui::SFML::Render(*this->p_render_window_);
	
	this->p_render_window_->display();
}


void Game::shutdown()
{
	ImGui::SFML::Shutdown();
}
