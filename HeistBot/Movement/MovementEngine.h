#pragma once
#include ".\..\C##\Vector2.h"
#include <array>
#include <iostream>
#include ".\..\C##\ListsExtensions.h"
#include ".\..\C##\Vector2.h"
#include <math.h>
#include <algorithm>
#include ".\..\C##\Misc.h"

using namespace CSS;

namespace HeistBot
{
    namespace Movement
    {
        class MovementEngine
        {
            public:
                float UpperLength = 6;
                float LowerLength = 10;
                float pastMotorAngles[2];

                Vector2 MotorAngles(Vector2 newPosition);

                void RotateMotorPos(int motorID, float angle, float speed);
                void RotateMotorVel(int motorID, float velocity, float time);

                void moveLeg(int legID, Vector2 pos, float speed);
        };
    }
}

