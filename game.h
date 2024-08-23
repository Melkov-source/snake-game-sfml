#ifndef GAME_H
#define GAME_H

#include "state-base.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void updateDeltaTime();
	void updateEvents();
	void update();
	void render();
	void run();

private:
	RenderWindow *m_renderWindow;
	Event m_event;

	Clock m_deltaTimeClock;
	float m_deltaTime;

	void createWindow();
};

#endif

