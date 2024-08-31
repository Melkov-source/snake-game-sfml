#ifndef GAME_H
#define GAME_H

#include "../Engine/Engine.h"

class Game
{
public:
    Game(Engine& engine);
    void Start();

private:
    Engine* _engine;
};

#endif // !GAME_H
