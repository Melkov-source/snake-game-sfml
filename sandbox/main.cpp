#include <iostream>
#include "./include/player.h"
#include "./include/map.h"

int main()
{
	Player player{ 5, 5 };

	char input{};

	do
	{
		Map map2;
		Map& map = map2;

		system("cls");
		show_info(player);
		map.draw(player);

		std::cout << "Enter pleas direction for player (W, A, S, D): ";
		std::cin >> input;

		move(player, input);
	} while (input != 'q');

	std::cin >> input;
}