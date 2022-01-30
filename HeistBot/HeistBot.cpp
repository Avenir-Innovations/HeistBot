// HeistBot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Vector2.h"
#include "MovementEngine.h"

using namespace std;

int main()
{
    int endThing = 1;
    cout << "How Many Rounds?\n";
    cin >> endThing;
    while (endThing > 0)
    {
        MovementEngine _ME;
        Vector2 pos;
        cout << "Position, Ladies and Gentlemen! Any Position!\nX: ";
        cin >> pos.x;
        cout << "Y: ";
        cin >> pos.y;
        Vector2 angles = _ME.MotorAngles(pos);
        cout << to_string(angles.x) + " , " + to_string(angles.y) + "\n";
        endThing--;
    }
    cout << "That Concludes Today's Show!\n";
    return 0;
}

