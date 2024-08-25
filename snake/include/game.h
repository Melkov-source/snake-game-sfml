#pragma once

#include "./states/state-base.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void update_delta_time();
	void update_events();
	void update();
	void render();
	void run();
	void shutdown();

private:
	sf::RenderWindow *p_render_window_;
	sf::Event event_;

	sf::Clock delta_time_clock_;
	sf::Time delta_time_;

	std::stack<StateBase*> states_;

	void initialize();
};

