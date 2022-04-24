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
    }
}

void MovementEngine::RotateMotorPos(int motorID, float angle, float speed, float torque)
{
    string dev_name("/dev/tty.usbmodemBE6118CD1"); //IDK How imma f***ing do this but gonna have to find the /dev/ directories for all the moteuses. (Motei?)
    int moteus_id = motorID;
    MoteusAPI api(dev_name, moteus_id); //For Use with the MoteusAPI

    // send one position with speed and torque limits
    double stop_position = RadToRot(angle);
    double velocity = speed;
    double max_torque = torque; //Example Value
    double feedforward_torque = 0; //Example Value
    api.SendPositionCommand(stop_position, velocity, max_torque, feedforward_torque); //For Use with the MoteusAPI
}
