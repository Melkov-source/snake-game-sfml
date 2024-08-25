#include "../include/player.h"

void show_info(const Player& player)
{
    std::cout << "Player info:" << '\n';
    std::cout << "X: " << player.x << '\n';
    std::cout << "Y: " << player.y << '\n';
}

void move(Player& player, const char direction_move)
{
    switch (direction_move)
    {
        case 'w':
            player.x--;
            break;
        case 's':
            player.x++;
            break;
        case 'a':
            player.y--;
            break;
        case 'd':
            player.y++;
            break;
        default:
            std::cout << "Not found direction type: " << direction_move << "\n";
            break;
    }
}
