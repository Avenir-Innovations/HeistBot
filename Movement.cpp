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
        Vector2 MotorAngles (Vector2 newPosition, Vector2 oldPosition) {
            int angles [2];
            float x, y;
            x = newPosition.x; y = newPosition.y;
            float X = sqrt(pow(x - oldPosition.x, 2) + pow(y - oldPosition.y, 2))

            float thetaAB = (PI / 2) - (X);


            return Vector2(angles[0], angles[1]);
        }

};