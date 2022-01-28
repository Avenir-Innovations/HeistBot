#include <iostream>

using namespace std;

struct Vector2
{
  float x;
  float y;

  Vector2 (float _x, float _y)
  {
    x = _x;
    y= _y;
  }
  Vector2 (float _f [2])
  {
    x = _f[0];
    y= _f[1];
  }

  inline Vector2 operator - (Vector2 a, Vector2 b)
  {
    return {a.x + b.x, a.y + b.y};
  }
};