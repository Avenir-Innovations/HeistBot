#include "Vector2.h"

using namespace CSS;

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
