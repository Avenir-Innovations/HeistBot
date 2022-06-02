#pragma once
#include "Vector2.h"
#include <array>
#include <thread>
#include <iostream>
#include "ListsExtensions.h"
#include "Vector2.h"
#include <math.h>
#include <algorithm>
<<<<<<< Updated upstream
=======
#include <unistd.h>
>>>>>>> Stashed changes
#include "MoteusAPI.h"
#include "Misc.h"

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

<<<<<<< Updated upstream
                Vector2 pastMotorAngles[4]; //See IDS for Order, Vector2s are (Theta A, Theta B)
                
                /*
                    Ids for Motors and Legs are as Follows:
                        Front Left  =  1   ;   A = 1   ;   B = 2
                        Front Right =  2   ;   A = 3   ;   B = 4
                        Back Left   =  3   ;   A = 5   ;   B = 6
                        Back Right  =  4   ;   A = 7   ;   B = 8
                        Arm         =  0   ;   
                */

=======
                float strideLength = 8;
                float strideHeight = 4.5;

                float RestingHeight = 12;

                float tolerance = 0.01;

                int walkCycle = 0;

                Vector2 pastMotorAngles[4]; //See IDs for Order, Vector2s are (Theta A, Theta B)
                
                /*
                    Ids for Motors and Legs are as Follows:
                        Front Left  =  1   ;   A = 1   ;   B = 2
                        Front Right =  2   ;   A = 3   ;   B = 4
                        Back Left   =  3   ;   A = 5   ;   B = 6
                        Back Right  =  4   ;   A = 7   ;   B = 8
                        Arm         =  0   ;   
                */

>>>>>>> Stashed changes
                //  KEEP ALL ANGLES IN RADIANS  //

                Vector2 MotorAngles(Vector2 newPosition); //Returns (Theta A, Theta B)

                float RadToRot (float _rad) { return _rad / ( 2 * PI ); }       // Radians to Rotations
                float RotToRad (float _rot) { return _rot * 2 * PI; }           // Rotations to Radians

                //  Motors Use Rotations. Use the Methods Above For Conversion. //

                void RotateMotorPos(int motorID, float angle, float speed, float torque = 1);     //Position Based Motor Movement
                void RotateMotorVel(int motorID, float velocity, float time);   //Velocity Based Motor Movement

                void moveLeg(int legID, Vector2 pos, float speed);

<<<<<<< Updated upstream
                void WalkForward(int Time);
=======
                void WalkForward(int Time, float speed = 1, int percentLeft = 100, int percentRight = 100);

                void Jump();
                void Crouch();

                float MotorPos (int id);
                Vector2 AnglePos (Vector2 angles);
                Vector2 LegPos (int id);

                bool VectorEqual (Vector2 a, Vector2 b);

                
>>>>>>> Stashed changes
        };
    }
}

