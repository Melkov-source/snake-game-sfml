#pragma once
#include "Grass.h"

class Map
{
  public:
    Map();
    virtual ~Map();

    void Initialize(const sf::Vector2f &scale, const sf::Vector2u &window_size);
    sf::Vector2f GetRandomPosition();

  private:
    Grass ***_ground;

    uint32_t _width;
    uint32_t _height;
};
