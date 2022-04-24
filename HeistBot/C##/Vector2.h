#pragma once
#include <list>
#include <tgmath.h>

using namespace std;

namespace CSS
{
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

            inline bool operator != (Vector2 a)
            {
                return ( x != a.x || y != a.y );
            }
    };

    inline float distance (Vector2 _1, Vector2 _2)
    {
        return sqrt(((_1.x - _2.x) * (_1.x - _2.x)) + ((_1.y - _2.y) * (_1.y - _2.y)));
    }
}

