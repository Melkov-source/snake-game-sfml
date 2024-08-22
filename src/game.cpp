#include <SFML/Graphics.hpp>;
#include <iostream>

#include "../include/game.h";

using namespace sf;
using namespace std;

class EventHandler
{
public:
    EventHandler(RenderWindow& window) : m_window(window)
    {

    }

    void update(Event& event)
    {
        while (m_window.pollEvent(event))
        {

            switch (event.type)
            {
            case Event::Closed:
                m_window.close();
                break;



            default:
                break;
            }
        }
    }

private:
    RenderWindow& m_window;
};



Game::Game(string tittleWindow)
{
    m_tittleWindow = tittleWindow;
}

void Game::run() 
{
    RenderWindow window(VideoMode(), m_tittleWindow, Style::Fullscreen);
    EventHandler eventHandler(window);

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        Event event;

        eventHandler.update(event);

        window.clear();

        //drawing...

        window.display();
    }
}


