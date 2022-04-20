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
                float UpperLength = 6;  //Length of Upper Segments
                float LowerLength = 10; //Length of Lower Segments

                Vector2 pastMotorAngles[4]; //See IDS for Order, Vector2s are (Theta A, Theta B)
                
                /*
                    Ids for Motors and Legs are as Follows:
                        Front Left  =  1   ;   A = 1   ;   B = 2
                        Front Right =  2   ;   A = 3   ;   B = 4
                        Back Left   =  3   ;   A = 5   ;   B = 6
                        Back Right  =  4   ;   A = 7   ;   B = 8
                        Arm         =  0   ;   
                */

                //  KEEP ALL ANGLES IN RADIANS  //

                Vector2 MotorAngles(Vector2 newPosition); //Returns (Theta A, Theta B)

                float RadToRot (float _rad) { return _rad / ( 2 * PI ); }       // Radians to Rotations
                float RotToRad (float _rot) { return _rot * 2 * PI; }           // Rotations to Radians

                //  Motors Use Rotations. Use the Methods Above For Conversion. //

                void RotateMotorPos(int motorID, float angle, float speed);     //Position Based Motor Movement
                void RotateMotorVel(int motorID, float velocity, float time);   //Velocity Based Motor Movement

                void moveLeg(int legID, Vector2 pos, float speed);

                void WalkForward(int Time);
        };
    }
}

