#pragma once


struct Vector2
{
    float x;
    float y;
};


class Transform
{
public:
    Vector2 position{};
    Vector2 scale{};
};
