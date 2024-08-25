#pragma once
#include "player.h"

constexpr unsigned short MAP_WIDTH = 10;
constexpr unsigned short MAP_HEIGHT = 10;

class Map
{
public:
	~Map();
	void draw(const Player& player) const;

private:
	char map_field_[MAP_WIDTH][MAP_HEIGHT]
	{
		{'X','X','X','X','X','X','X','X','X', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ', 'X'},
		{'X','X','X','X','X','X','X','X','X', 'X'}
	};
};

