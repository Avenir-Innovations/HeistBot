#include <cstdio>
#include <iostream>
#include <string>
#include "Vector2.h"
#include "MovementEngine.h"
#include "MappingEngine.h"
#include "Shapes.h"
#include "Misc.h"

using namespace std;
using namespace HeistBot;
using namespace CSS;

int main()
{
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        cout << "Welcome to Testing For HeistBOT. What Are You Testing?\n\n   1: Movement\n   2: Vision\n 3: Mapping\n   4: Intelligence\n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): ";
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    movement();
                }
                break;
            case 2:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    vision();
                }
                break;
            case 3:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    mapping();
                }
                break;
            case 4:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    intelligence();
                }
                break;
            case 5:
                quit = true;
                break;
            default:
                break;
        }
        
    }
    cout << "That Concludes Today's Testing.\n\nPress Any Button to Exit.";
    cin >> _h;
    
    return 0;
}

void movement()
{
    string _h = "";
    bool quit = false;
    while (quit == false)
    {
        cout << "Welcome to the HeistBOT Movement Testing Screen!\nWhat Do You Want to Test?\n\n   Option 1: Inverse Kinematics\n   Option 2: Single Motor Movement\n   Option 3: Leg Movement\n   Option 4: Walking\n\nSelect an Option (1,2,3) to Continue:\t";
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Times?\n\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Movement::MovementEngine _ME;
                    Vector2 pos;
                    cout << "Input a Position\nCoordinates are in Inches and 0,0 Being a Cartesian Coordinate Grid Centered at the 2 Motors For a Leg\n\n   X: ";
                    cin >> pos.x;
                    cout << "   Y: ";
                    cin >> pos.y;
                    Vector2 angles = _ME.MotorAngles(pos);
                    cout << to_string(angles.x) + " , " + to_string(angles.y) + "\n";
                    endThing--;
                }
                break;
            case 2:
                cout << "How Many Times?\n\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Movement::MovementEngine _ME;
                    float pos = 0;
                    float speed = 1;
                    float torque = 1;
                    int motorID = 1;
                    cout << "What Motor Do You Wish To Move?\n\n   ID: ";
                    cin >> motorID;
                    cout << "\nInput an Angle To Move the Motor to In Radians\n\n   θ: ";
                    cin >> pos;
                    cout << "\nInput a Speed\n\n   Speed: ";
                    cin >> speed;
                    cout << "\nInput a Torque\n\n   τ: ";
                    cin >> torque;
                    cout << "\nMoving...\n";

                    _ME.RotateMotorPos(motorID, pos, speed);

                    cout << "Moved.";
                    endThing--;
                }
                break;
            case 3:
                cout << "How Many Times?\n\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Movement::MovementEngine _ME;
                    Vector2 pos = Vector2(0,0);
                    float speed = 1;
                    float torque = 1;
                    int legID = 1;
                    cout << "What Leg Do You Wish To Move?\n\n   ID: ";
                    cin >> legID;
                    cout << "Input a Position\nCoordinates are in Inches and 0,0 Being a Cartesian Coordinate Grid Centered at the 2 Motors For a Leg\n\n   X: ";
                    cin >> pos.x;
                    cout << "   Y: ";
                    cin >> pos.y;
                    cout << "\nInput a Speed\n\n   Speed: ";
                    cin >> speed;
                    cout << "\nMoving...\n";

                    _ME.moveLeg(legID, pos, speed);

                    cout << "Moved.";
                    endThing--;
                }
                break;
            case 4:
                cout << "How Many Times?\n\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Movement::MovementEngine _ME;
                    int strides = 1;
                    cout << "How Many Strides?\n\n   Strides: ";
                    cin >> strides;
                    cout << "\nMoving...\n";

                    _ME.WalkForward(strides);

                    cout << "Moved.";
                    endThing--;
                }
                break;
            case 5:
                quit = true;
                break;
            default:
                break;
        }
    }
    cout << "That Concludes Movement Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}

void vision()
{
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        cout << "Welcome to HeistBOT Vision Testing. What Do You Want to Test?\n\n   1:       \n   2:       \n   3:       \n   4:       \n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): "; //Add Placeholder Values
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 2:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 3:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 4:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 5:
                quit = true;
                break;
            default:
                break;
        }
        
    }
    cout << "That Concludes Vision Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}

void mapping()
{
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        cout << "Welcome to HeistBOT Mapping Testing. What Do You Want to Test?\n\n   1:       \n   2:       \n   3:       \n   4:       \n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): "; //Add Placeholder Values
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 2:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 3:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 4:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 5:
                quit = true;
                break;
            default:
                break;
        }
        
    }
    cout << "That Concludes Mapping Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}

void intelligence()
{
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        cout << "Welcome to HeistBOT Intelligence Testing. What Do You Want to Test?\n\n   1:       \n   2:       \n   3:       \n   4:       \n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): "; //Add Placeholder Values
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 2:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 3:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 4:
                cout << "How Many Times?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    //Do Stuff
                }
                break;
            case 5:
                quit = true;
                break;
            default:
                break;
        }
        
    }
    cout << "That Concludes Intelligence Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}