#pragma once
#include "Vector2.h"
#include <array>
#include <iostream>
#include "ListsExtensions.h"
#include "Vector2.h"
#include <math.h>
#include <algorithm>
#include "Misc.h"

class MovementEngine
{
public:
    float UpperLength = 1;
    float LowerLength = 1;

    float pastMotorAngles[2];

    Vector2 MotorAngles(Vector2 newPosition);
};

