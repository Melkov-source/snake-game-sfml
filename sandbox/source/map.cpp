#include "../include/map.h"

Map::~Map()
{
	std::cout << "Map destroyed for this: " << this << '\n';
}

void Map::draw(const Player& player) const
{
	for (int row = 0; row < MAP_WIDTH; row++)
	{
		for (int column = 0; column < MAP_HEIGHT; column++)
		{
			if (player.x == row && player.y == column)
			{
				std::cout << 'P';
			}
			else
			{
				const char value = this->map_field_[row][column];
				std::cout << value;
			}
		}

		std::cout << '\n';
	}
}
