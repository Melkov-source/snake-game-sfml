#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;


class Game
{
public:
	Game();
	virtual ~Game();

	void updateEvents();
	void update();
	void render();
	void run();

private:
	RenderWindow *m_renderWindow;
	Event m_event;

	void createWindow();
};

#endif

