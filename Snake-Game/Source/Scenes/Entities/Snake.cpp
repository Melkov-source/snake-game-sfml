#include "Snake.h"

Snake::Snake() : GameObject("Snake")
{
    _snakeTexture = AssetsManager::LoadTexture("Assets/textures/snake-atlass.png");

    _speed = 64.0f;
    _updateTimer = 0.0f;
    _updateInterval = 0.1f;
}

Snake::~Snake()
{
    Debug::Logger::Log("Snake destroyed");
}

void Snake::Start()
{
    const auto head = new GameObject("SnakeHead");
    
    head->setScale(getScale());

    _direction = {this->getScale().x * 64, 0};

    const auto sprite = head->AddComponent<SpriteComponent>();

    sprite->SetTexture(*_snakeTexture);
    sprite->SetTextureRect(SNAKE_HEAD);

    head->AddComponent<LayerComponent>()->Order = 20;
    
    _elements.push_back(head);

    AddMass(2);
}

void Snake::Update(const float deltaTime)
{
    const float step_size = this->getScale().x * 64;

    /*if (GetEngine()->Event.type == sf::Event::KeyPressed)
    {
        switch (GetEngine()->Event.key.code)
        {
            case sf::Keyboard::Key::Left:
                this->_direction = sf::Vector2f(-step_size, 0);
                break;
            case sf::Keyboard::Key::Right:
                this->_direction = sf::Vector2f(step_size, 0);
                break;
            case sf::Keyboard::Key::Up:
                this->_direction = sf::Vector2f(0, -step_size);
                break;
            case sf::Keyboard::Key::Down:
                this->_direction = sf::Vector2f(0, step_size);
                break;
        }
    }*/

    _updateTimer += deltaTime;

    if (_updateTimer < _updateInterval)
    {
        return;
    }
    
    _updateTimer = 0;

    

    for (size_t index = _elements.size() - 1, target = 0; index > target; index--)
    {
        const auto element =  _elements[index];
        const auto previous_element = _elements[index - 1];

        const auto target_position = previous_element->getPosition();
        
        element->setPosition(target_position);
    }

    _elements[0]->move(_direction.x, _direction.y);
}

void Snake::SetSpeed(float speed)
{
    _updateInterval = speed;
}

float Snake::GetSpeed()
{
    return _updateInterval;
}

void Snake::AddMass(const int32_t mass)
{
    for (int index = 0; index < mass; index++)
    {
        const auto body = new GameObject("SnakeBody");

        _elements.push_back(body);

        const auto previous_element = _elements[_elements.size() - 2];
        
        body->setPosition(previous_element->getPosition());
        body->setScale(getScale());

        const auto sprite = body->AddComponent<SpriteComponent>();

        sprite->SetTexture(*_snakeTexture);
        sprite->SetTextureRect(SNAKE_BODY);

        body->AddComponent<LayerComponent>()->Order = 10;
    }
}

void Snake::SetPositionHead(const sf::Vector2f& position)
{
    _elements[0]->setPosition(position);
}
