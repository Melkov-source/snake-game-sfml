#include "game.h"

Game::Game()
{

}

Game::~Game()
{
	delete this->m_renderWindow;
}

void Game::updateEvents()
{
	while (this->m_renderWindow->pollEvent(this->m_event))
	{
		switch (this->m_event.type)
		{
			case Event::Closed:
				this->m_renderWindow->close();
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	this->m_renderWindow->clear();

	this->m_renderWindow->display();
}

void Game::run()
{
	while (this->m_renderWindow->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::createWindow()
{
	VideoMode videoMode(800, 800);

	this->m_renderWindow = new RenderWindow(videoMode, "Snake");
}
