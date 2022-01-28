#include <iostream>
#include "Movement.cpp"

using namespace std;

int main () {
  MovementEngine _me;
  _me.MotorAngles({0,1}, {0,0});
  cout << "H";
  return 0;
}