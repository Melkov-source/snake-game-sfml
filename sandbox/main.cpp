#include <iostream>
#include "player.h"
#include "map.h"

int main()
{
	Player player{ 5, 5 };

	char input{};

	do
	{
		constexpr Map map;

		system("cls");
		show_info(player);
		map.draw(player);

		std::cout << "Enter pleas direction for player (W, A, S, D): ";
		std::cin >> input;

		move(player, input);
	} while (input != 'q');
}