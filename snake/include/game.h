#pragma once

#include "state-base.h"

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
	RenderWindow *p_render_window_;
	Event event_;

	Clock delta_time_clock_;
	Time delta_time_;

	void initialize();
};

