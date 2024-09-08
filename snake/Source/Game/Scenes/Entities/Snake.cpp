// Snake.cpp
#include "Snake.h"
#include "SnakeElement.h"
#include "../../Application.h"

Snake::Snake() : GameObject("Snake")
{
    _snakeTexture = AssetsManager::LoadTexture("assets/textures/snake-atlass.png");

    _speed = 64.0f;
    _updateTimer = 0.0f;
    _updateInterval = 0.2f;
}

Snake::~Snake()
{
}

void Snake::Start()
{
    SnakeElement* head = CreateSnakeElement(SnakeElement::HEAD);
    head->setPosition(sf::Vector2f(0, 0));
    head->SetOrder(20);
    
    _elements.push_back(head);
    
    for (int i = 0; i < 150; ++i)
    {
        SnakeElement* body = CreateSnakeElement(SnakeElement::BODY);

        _elements.push_back(body);
    }
}

void Snake::Update(const float deltaTime)
{
    _updateTimer += deltaTime;

    if (_updateTimer < _updateInterval)
    {
        return;
    }
    
    _updateTimer = 0;

    auto direction = sf::Vector2f(0, 0);

    const float step_size = this->getScale().x * 64;

    switch (Application::Core->KeyPressed)
    {
        case sf::Keyboard::Key::Left:
            direction = sf::Vector2f(-step_size, 0);
            break;
        case sf::Keyboard::Key::Right:
            direction = sf::Vector2f(step_size, 0);
            break;
        case sf::Keyboard::Key::Up:
            direction = sf::Vector2f(0, -step_size);
            break;
        case sf::Keyboard::Key::Down:
            direction = sf::Vector2f(0, step_size);
            break;
    }

    for (size_t i = _elements.size() - 1; i > 0; --i) {
        _elements[i]->setPosition(_elements[i - 1]->getPosition());
    }

    _elements[0]->move(direction.x, direction.y);
}

void Snake::SetSpeed(float speed)
{
    _updateInterval = speed;
}

float Snake::GetSpeed()
{
    return _updateInterval;
}

SnakeElement* Snake::CreateSnakeElement(SnakeElement::SNAKE_ELEMENT type)
{
    SnakeElement* element = new SnakeElement(*_snakeTexture, type);
    element->setScale(getScale());
    return element;
}
