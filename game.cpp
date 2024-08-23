#include "game.h"

Game::Game()
{
	this->createWindow();
}

Game::~Game()
{
	delete this->m_renderWindow;
}

void Game::updateDeltaTime()
{
	this->m_deltaTime = this->m_deltaTimeClock.restart().asSeconds();

	std::cout << this->m_deltaTime << std::endl;
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
	this->updateEvents();
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
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}

void Game::createWindow()
{
	ifstream windowConfig("configs/window.ini");

	string title = "None";
	VideoMode videoMode(800, 600);
	unsigned int targetFrameRate = 120;
	bool isVerticalSync = false;

	if (windowConfig.is_open())
	{
		getline(windowConfig, title);
		windowConfig >> videoMode.width >> videoMode.height;
		windowConfig >> targetFrameRate;
		windowConfig >> isVerticalSync;
	}

	this->m_renderWindow = new RenderWindow(videoMode, title);

	this->m_renderWindow->setFramerateLimit(targetFrameRate);
	this->m_renderWindow->setVerticalSyncEnabled(isVerticalSync);
}
