#pragma once
#include ".\..\C##\Vector2.h"
#include <array>
#include <iostream>
#include ".\..\C##\ListsExtensions.h"
#include ".\..\C##\Vector2.h"
#include <math.h>
#include <algorithm>
#include ".\..\C##\Misc.h"

using namespace Extras;

namespace HeistBot
{
    namespace Movement
    {
        class MovementEngine
        {
            public:
                float UpperLength = 1;
                float LowerLength = 1;

                float pastMotorAngles[2];

                Vector2 MotorAngles(Vector2 newPosition);
        };
    }
}

