#pragma once

#include <iostream>

struct Player
{
	int x;
	int y;
};

void show_info(const Player& player);
void move(Player& player, char direction_move);