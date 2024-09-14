#include "Map.h"
#include "Debug/Logger.h"

Map::Map() = default;

Map::~Map()
{
    delete[] _ground;
}

void Map::Initialize(const sf::Vector2f &scale, const sf::Vector2u &window_size)
{
    constexpr unsigned int tile_size = 64;

    _width = window_size.x / scale.x / tile_size;
    _height = window_size.y / scale.y / tile_size;

    _ground = new Grass **[_width];

    for (unsigned int x = 0; x < _width; x++)
    {
        _ground[x] = new Grass *[_height];

        for (unsigned int y = 0; y < _height; y++)
        {
            const auto grass = new Grass();

            _ground[x][y] = grass;

            grass->setPosition(sf::Vector2f(x * tile_size * scale.x, y * tile_size * scale.y));
            grass->setScale(scale);
        }
    }
}

sf::Vector2f Map::GetRandomPosition()
{
    srand(time(0));
    if (_width == 0 || _height == 0)
    {
        return sf::Vector2f(0, 0);
    }

    uint32_t random_x = std::rand() % _width;
    uint32_t random_y = std::rand() % _height;

    const auto grass = _ground[random_x][random_y];

    return grass->getPosition();
}
