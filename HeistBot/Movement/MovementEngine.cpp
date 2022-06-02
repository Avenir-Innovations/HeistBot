#include "MovementEngine.h"

using namespace HeistBot;
using namespace Movement;
using namespace CSS;

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

<<<<<<< Updated upstream
=======
bool MovementEngine::VectorEqual (Vector2 a, Vector2 b)
{
    return ((a.x - b.x <= tolerance) && (a.y - b.y <= tolerance));
}

Vector2 MovementEngine::AnglePos(Vector2 angles)
{
    float x, y;
    x = angles.x; y = angles.y;

    float thetaAB = y - x;
    float thetaL = (x + y) / 2;

    float A = sin(thetaAB / 2) * UpperLength;
    float B = sqrt(LowerLength * LowerLength - A * A);
    float C = B + cos(thetaAB / 2) * UpperLength;

    return Vector2({C * cos(thetaL), C * sin(thetaL)});
}

float MovementEngine::MotorPos(int id)
{
    string dev_name("/dev/ttyACM0"); //I DID IT WOOOOOOOOOOOOOOOOOOOOOOOOOOO
    MoteusAPI api(dev_name, id);

    State state;
    api.ReadState(state.EN_Position());

    return RotToRad(state.position);
}

Vector2 MovementEngine::LegPos (int id)
{
    Vector2 Motors = Vector2();

    switch (id)
    {
        case 1:
            Motors = Vector2(1,2);
            break;
        case 2:
            Motors = Vector2(3,4);
            break;
        case 3:
            Motors = Vector2(5,6);
            break;
        case 4:
            Motors = Vector2(7,8);
            break;
    }

    Vector2 Angles = Vector2();

    Vector2 _offset = MotorAngles(Vector2(0,-12));

    Angles.x = -1 * MotorPos(Motors.x) + _offset.x;
    Angles.y = -1 * MotorPos(Motors.y) + _offset.y;

    return AnglePos(Angles);
}

>>>>>>> Stashed changes
void MovementEngine::moveLeg(int legID, Vector2 pos, float speed)
{
    Vector2 Motors = Vector2();

    switch (legID)
    {
        case 1:
            Motors = Vector2(1,2);
            break;
        case 2:
            Motors = Vector2(3,4);
            break;
        case 3:
            Motors = Vector2(5,6);
            break;
        case 4:
            Motors = Vector2(7,8);
            break;
    }

    Vector2 Thetas = MotorAngles(pos);

    //Unsure If This Moves Just One Motor at a Time or if it Will Execute Both at Once.
    RotateMotorPos(Motors.x, Thetas.x, speed);
    RotateMotorPos(Motors.y, Thetas.y, speed);

}

<<<<<<< Updated upstream
void MovementEngine::WalkForward(int Time)
{
    float strideLength = 1.2; //Temporary
    for (int i = 0; i < Time; i++)
    {
        //Do these 4 at the same time
        moveLeg(1, Vector2(0, -13.4 / 2), 1);
        moveLeg(3, Vector2(0, -13.4 / 2), 1);
        moveLeg(2, Vector2(0, -13.4), 1);
        moveLeg(4, Vector2(0, -13.4), 1);
        //Do these 4 at the same time
        moveLeg(1, Vector2(strideLength, -13.4), 1);
        moveLeg(3, Vector2(strideLength, -13.4), 1);
        moveLeg(2, Vector2(-strideLength, -13.4), 1);
        moveLeg(4, Vector2(-strideLength, -13.4), 1);
        //Do these 4 at the same time
        moveLeg(1, Vector2(0, -13.4), 1);
        moveLeg(3, Vector2(0, -13.4), 1);
        moveLeg(2, Vector2(0, -13.4 / 2), 1);
        moveLeg(4, Vector2(0, -13.4 / 2), 1);
        //Do these 4 at the same time
        moveLeg(1, Vector2(-strideLength, -13.4), 1);
        moveLeg(3, Vector2(-strideLength, -13.4), 1);
        moveLeg(2, Vector2(strideLength, -13.4), 1);
        moveLeg(4, Vector2(strideLength, -13.4), 1);
=======
//

void MovementEngine::WalkForward(int Times, float speed, int percentLeft, int percentRight)
{
    bool skip = Times == -1;
    if (Times < 0) Times *= -1;
    float _sh = -strideHeight;

    if (walkCycle = 0) walkCycle = 1;

    for (int i = 0; i < Times; i++)
    {
        switch (walkCycle)
        {
            case 0: //will mess with if needed
            {
                //Do these 4 at the same time
                moveLeg(1, Vector2(0, _sh), speed);
                moveLeg(2, Vector2(0, -RestingHeight), speed);
                moveLeg(3, Vector2(strideLength * percentLeft / 100, -RestingHeight), speed);
                moveLeg(4, Vector2(-strideLength * percentRight / 100, -RestingHeight), speed);
                //check if they are at their desired positions
                bool atPos = false;
                while (!atPos)
                {
                    bool _h = true;
                    if (VectorEqual(LegPos(1), Vector2(0, _sh))) _h = false;
                    if (VectorEqual(LegPos(2), Vector2(0, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(3), Vector2(strideLength * percentLeft / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(4), Vector2(-strideLength * percentRight / 100, -RestingHeight))) _h = false;
                    atPos = _h;
                }
                walkCycle++;
            }
            break;
            case 1:
            {
                //Do these 4 at the same time
                moveLeg(1, Vector2(0, _sh), speed);
                moveLeg(2, Vector2(0, -RestingHeight), speed);
                moveLeg(3, Vector2(strideLength * percentLeft / 100, -RestingHeight), speed);
                moveLeg(4, Vector2(-strideLength * percentRight / 100, -RestingHeight), speed);
                //check if they are at their desired positions
                bool atPos = false;
                while (!atPos)
                {
                    bool _h = true;
                    if (VectorEqual(LegPos(1), Vector2(0, _sh))) _h = false;
                    if (VectorEqual(LegPos(2), Vector2(0, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(3), Vector2(strideLength * percentLeft / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(4), Vector2(-strideLength * percentRight / 100, -RestingHeight))) _h = false;
                    atPos = _h;
                }
                walkCycle++;
            }
            break;
            case 2:
            {
                //Do these 4 at the same time
                moveLeg(1, Vector2(strideLength * percentLeft / 100, -RestingHeight), speed);
                moveLeg(2, Vector2(-strideLength * percentRight / 100, -RestingHeight), speed);
                moveLeg(3, Vector2(0, -RestingHeight), speed);
                moveLeg(4, Vector2(0, _sh), speed);
                //check if they are at their desired positions
                bool atPos = false;
                while (!atPos)
                {
                    bool _h = true;
                    if (VectorEqual(LegPos(1), Vector2(strideLength * percentLeft / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(2), Vector2(-strideLength * percentRight / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(3), Vector2(0, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(4), Vector2(0, _sh))) _h = false;
                    atPos = _h;
                }
                walkCycle++;
            }
            break;
            case 3:
            {
                //Do these 4 at the same time
                moveLeg(1, Vector2(0, -RestingHeight), speed);
                moveLeg(2, Vector2(0, _sh), speed);
                moveLeg(3, Vector2(-strideLength * percentLeft / 100, -RestingHeight), speed);
                moveLeg(4, Vector2(strideLength * percentRight / 100, -RestingHeight), speed);
                //check if they are at their desired positions
                bool atPos = false;
                while (!atPos)
                {
                    bool _h = true;
                    if (VectorEqual(LegPos(1), Vector2(0, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(2), Vector2(0, _sh))) _h = false;
                    if (VectorEqual(LegPos(3), Vector2(-strideLength * percentLeft / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(4), Vector2(strideLength * percentRight / 100, -RestingHeight))) _h = false;
                    atPos = _h;
                }
                walkCycle++;
            }
            break;
            case 4:
            {
                //Do these 4 at the same time
                moveLeg(1, Vector2(-strideLength * percentLeft / 100, -RestingHeight), speed);
                moveLeg(2, Vector2(strideLength * percentRight / 100, -RestingHeight), speed);
                moveLeg(3, Vector2(0, _sh), speed);
                moveLeg(4, Vector2(0, -RestingHeight), speed);
                //check if they are at their desired positions
                bool atPos = false;
                while (!atPos)
                {
                    bool _h = true;
                    if (VectorEqual(LegPos(1), Vector2(-strideLength * percentLeft / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(2), Vector2(strideLength * percentRight / 100, -RestingHeight))) _h = false;
                    if (VectorEqual(LegPos(3), Vector2(0, _sh))) _h = false;
                    if (VectorEqual(LegPos(4), Vector2(0, -RestingHeight))) _h = false;
                    atPos = _h;
                }
                walkCycle = 1;
            }
            break;
        }
    }
    if (!skip) walkCycle = 0;
    if (walkCycle = 0) 
    {
        //Do these 4 at the same time
        moveLeg(1, Vector2(0, RestingHeight), speed);
        moveLeg(2, Vector2(0, RestingHeight), speed);
        moveLeg(3, Vector2(0, RestingHeight), speed);
        moveLeg(4, Vector2(0, RestingHeight), speed);
        //check if they are at their desired positions
        bool atPos = false;
        while (!atPos)
        {
            bool _h = true;
            if (VectorEqual(LegPos(1), Vector2(0, RestingHeight))) _h = false;
            if (VectorEqual(LegPos(2), Vector2(0, RestingHeight))) _h = false;
            if (VectorEqual(LegPos(3), Vector2(0, RestingHeight))) _h = false;
            if (VectorEqual(LegPos(4), Vector2(0, RestingHeight))) _h = false;
            atPos = _h;
        }
    }
}

void MovementEngine::Jump ()
{
    moveLeg(1, Vector2(0, -1), 0.5);
    moveLeg(2, Vector2(0, -1), 0.5);
    moveLeg(3, Vector2(0, -1), 0.5);
    moveLeg(4, Vector2(0, -1), 0.5);
    //check if they are at their desired positions
    bool atPos = false;
    while (!atPos)
    {
        bool _h = true;
        if (VectorEqual(LegPos(1), Vector2(0, -1))) _h = false;
        if (VectorEqual(LegPos(2), Vector2(0, -1))) _h = false;
        if (VectorEqual(LegPos(3), Vector2(0, -1))) _h = false;
        if (VectorEqual(LegPos(4), Vector2(0, -1))) _h = false;
        atPos = _h;
    }
    moveLeg(1, Vector2(0, -13), 0.5);
    moveLeg(2, Vector2(0, -13), 0.5);
    moveLeg(3, Vector2(0, -13), 0.5);
    moveLeg(4, Vector2(0, -13), 0.5);
    //check if they are at their desired positions
    atPos = false;
    while (!atPos)
    {
        bool _h = true;
        if (VectorEqual(LegPos(1), Vector2(0, -13))) _h = false;
        if (VectorEqual(LegPos(2), Vector2(0, -13))) _h = false;
        if (VectorEqual(LegPos(3), Vector2(0, -13))) _h = false;
        if (VectorEqual(LegPos(4), Vector2(0, -13))) _h = false;
        atPos = _h;
    }
    sleep(1);
    moveLeg(1, Vector2(0, -13), 0.5);
    moveLeg(2, Vector2(0, -13), 0.5);
    moveLeg(3, Vector2(0, -13), 0.5);
    moveLeg(4, Vector2(0, -13), 0.5);
    //check if they are at their desired positions
    atPos = false;
    while (!atPos)
    {
        bool _h = true;
        if (VectorEqual(LegPos(1), Vector2(0, -RestingHeight))) _h = false;
        if (VectorEqual(LegPos(2), Vector2(0, -RestingHeight))) _h = false;
        if (VectorEqual(LegPos(3), Vector2(0, -RestingHeight))) _h = false;
        if (VectorEqual(LegPos(4), Vector2(0, -RestingHeight))) _h = false;
        atPos = _h;
>>>>>>> Stashed changes
    }
}

void MovementEngine::RotateMotorPos(int motorID, float angle, float speed, float torque)
{
<<<<<<< Updated upstream
    string dev_name("/dev/tty.usbmodemBE6118CD1"); //IDK How imma f***ing do this but gonna have to find the /dev/ directories for all the moteuses. (Motei?)
    int moteus_id = motorID;
    MoteusAPI api(dev_name, moteus_id); //For Use with the MoteusAPI

    // send one position with speed and torque limits
    double stop_position = RadToRot(angle);
    double velocity = speed;
    double max_torque = torque; //Example Value
    double feedforward_torque = 0; //Example Value
=======
    string dev_name("/dev/ttyACM0"); //I DID IT WOOOOOOOOOOOOOOOOOOOOOOOOOOO
    MoteusAPI api(dev_name, motorID); //For Use with the MoteusAPI

    // send one position with speed and torque limits
    double stop_position = RadToRot(angle);
    double velocity = RadToRot(speed);
    double max_torque = torque;
    double feedforward_torque = 0;
>>>>>>> Stashed changes
    api.SendPositionCommand(stop_position, velocity, max_torque, feedforward_torque); //For Use with the MoteusAPI
}
