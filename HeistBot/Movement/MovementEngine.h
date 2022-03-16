#pragma once
#include ".\..\Extras\Vector2.h"
#include <array>
#include <iostream>
#include ".\..\Extras\ListsExtensions.h"
#include ".\..\Extras\Vector2.h"
#include <math.h>
#include <algorithm>
#include ".\..\Extras\Misc.h"

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

