#include "MovementEngine.h"

const float PI = std::atan(1.0) * 4;

Vector2 MovementEngine::MotorAngles(Vector2 newPosition)
{
    float x, y;
    x = newPosition.x; y = newPosition.y;
    float X = sqrt(pow(x, 2) + pow(y, 2));

    float thetaAB = (PI / 2) - acos((UpperLength + LowerLength - X) / (2 * UpperLength * LowerLength));
    float thetaL = asin(x / X);

    float thetaA = thetaL - (thetaAB / 2); float thetaB = thetaL + (thetaAB / 2);

    return Vector2({thetaA, thetaB});
}