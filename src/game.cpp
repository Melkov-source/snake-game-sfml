#include <SFML/Graphics.hpp>;
#include <iostream>

#include "../include/game.h";

using namespace sf;
using namespace std;

Game::Game(string tittleWindow)
{
    m_tittleWindow = tittleWindow;
}

void Game::run() 
{
    RenderWindow window(VideoMode(), m_tittleWindow, Style::Fullscreen);

    RectangleShape shape({100, 100});

    Vector2u windowSize = window.getSize();
    Vector2f shapeSize = shape.getSize();

    Vector2f centerPosition(windowSize.x / 2 - shapeSize.x / 2, windowSize.y / 2 - shapeSize.y / 2);

    shape.setPosition(centerPosition);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}