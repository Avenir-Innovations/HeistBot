#pragma once
#include <list>
using namespace std;
class Vector2
{
    public:
        float x;
        float y;

        Vector2();
        Vector2(float _x, float _y);
        Vector2(float _f[2]);

        inline Vector2 operator + (Vector2 a)
        {
            return {x + a.x, y + a.y};
        }

        inline Vector2 operator - (Vector2 a)
        {
            return { x - a.x, y - a.y };
        }

        inline bool operator == (Vector2 a)
        {
            return ( x == a.x && y == a.y );
        }
};


