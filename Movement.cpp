#include <iostream>
#include <math.h>
#include "structs.h"

using namespace std;

const float PI = std::atan(1.0)*4;

int main () {
  cout << "H";
  return 0;
}

class MovementEngine
{
  public:
      float UpperLength = 1;
      float LowerLength = 1;

      float pastMotorAngles [2];

      Vector2 MotorAngles (Vector2 newPosition) {
          int angles [2];
          float x, y;
          x = newPosition.x; y = newPosition.y;
          float X = sqrt(pow(x, 2) + pow(y, 2))

          float thetaAB = (PI / 2) -  acos((UpperLength + LowerLength - X) / (2 * UpperLength * LowerLength));
          float thetaL = asin(x / X);

          float thetaA = thetaL - (thetaAB / 2); float thetaB = thetaL + (thetaAB / 2);
          angles = {thetaA, thetaB};

          return Vector2(angles);
      }
};