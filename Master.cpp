#include <iostream>
#include "structs.h"
#include "Movement.cpp"

using namespace std;

int main () {
  MovementEngine _ME;
  Vector2 angles = _ME.MotorAngles({0,1});
  cout << angles.x.ToString() + " , " angles.y.ToString();
  return 0;
}