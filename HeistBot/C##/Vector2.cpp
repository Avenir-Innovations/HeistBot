#include "Vector2.h"

using namespace Extras;

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

Vector2::Vector2(float _f[2])
{
    x = _f[0];
    y = _f[1];
}

float distance (Vector2 _1, Vector2 _2)
{
    return sqrt(((_1.x - _2.x) * (_1.x - _2.x)) + ((_1.y - _2.y) * (_1.y - _2.y)));
}