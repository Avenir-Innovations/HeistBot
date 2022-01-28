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
};