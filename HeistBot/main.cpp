#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include "Vector2.h"
#include "MovementEngine.h"
#include "MappingEngine.h"
#include "Shapes.h"
#include "Misc.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Joystick.hpp>

using namespace std;
using namespace HeistBot;
using namespace CSS;



static void movement()
{
    string _h = "";
    bool quit = false;
    while (quit == false)
    {
        cout << "Welcome to the HeistBOT Movement Testing Screen!\nWhat Do You Want to Test?\n\n   Option 1: Inverse Kinematics\n   Option 2: Single Motor Movement\n   Option 3: Leg Movement\n   Option 4: Walking\n   Option 5: Controller\n   Option 6: Controller Movement\n\nSelect an Option (1,2,3,4,5) to Continue:\t";
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                {
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
                }
            case 2:
                {
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
                }
            case 3:
                {
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
                }
            case 4:
                {
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
                }
            case 5:
                {
                    bool __quit = false;
                    while (!__quit)
                    {
                        cout << "Entering Controller Mode..." << endl;
                        sleep(1);
                        cout << "3" << endl;
                        sleep(1);
                        cout << "2" << endl;
                        sleep(1);
                        cout << "1" << endl;
                        sleep(1);
                        Movement::MovementEngine _ME;
                        sf::Joystick::update();
                        cout << sf::Joystick::Count << endl;
                        sleep(1);
                        if (!sf::Joystick::isConnected(0))
                        {
                            cout << "No Controller Connected to 0" << endl;
                            sleep(5);
                            __quit = true;
                        }
                        else
                        {
                            cout << "Controller 0 Connected." << endl;
                            string _cname = "Name: " + sf::Joystick::getIdentification(0).name;
                            cout << _cname << endl;
                            //cout << "Manufacturer: " + sf::Joystick::getIdentification(0).vendorId << endl;
                            //cout << "Product ID: " + sf::Joystick::getIdentification(0).productId << endl;
                            sleep(5);
                            cout << "Starting Loop." << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::X) << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::Y) << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::Z) << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::R) << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::U) << endl;
                            cout << sf::Joystick::hasAxis(0, sf::Joystick::V) << endl;
                            cout << sf::Joystick::getButtonCount(0) << endl;
                            sleep(5);
                            bool axese = true;
                            for (int i = 1; i <= 15; i++)
                            {
                                sf::Joystick::update();
                                cout << i << endl;
                                cout << "Axis 1: " << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << endl;
                                cout << "Axis 2: " << sf::Joystick::getAxisPosition(0, sf::Joystick::Y) << endl;
                                cout << "Axis 1: " << sf::Joystick::getAxisPosition(0, sf::Joystick::Z) << endl;
                                cout << "Axis 2: " << sf::Joystick::getAxisPosition(0, sf::Joystick::R) << endl;
                                cout << "Axis 1: " << sf::Joystick::getAxisPosition(0, sf::Joystick::U) << endl;
                                cout << "Axis 2: " << sf::Joystick::getAxisPosition(0, sf::Joystick::V) << endl;
                                if (sf::Joystick::isButtonPressed(0,0)) cout << "Pressed 0" << endl;
                                if (sf::Joystick::isButtonPressed(0,1)) cout << "Pressed 1" << endl;
                                if (sf::Joystick::isButtonPressed(0,2)) cout << "Pressed 2" << endl;
                                if (sf::Joystick::isButtonPressed(0,3)) cout << "Pressed 3" << endl;
                                if (sf::Joystick::isButtonPressed(0,4)) cout << "Pressed 4" << endl;
                                if (sf::Joystick::isButtonPressed(0,5)) cout << "Pressed 5" << endl;
                                if (sf::Joystick::isButtonPressed(0,6)) cout << "Pressed 6" << endl;
                                if (sf::Joystick::isButtonPressed(0,7)) cout << "Pressed 7" << endl;
                                if (sf::Joystick::isButtonPressed(0,8)) cout << "Pressed 8" << endl;
                                if (sf::Joystick::isButtonPressed(0,9)) cout << "Pressed 9" << endl;
                                if (sf::Joystick::isButtonPressed(0,10)) cout << "Pressed 10" << endl;
                                if (sf::Joystick::isButtonPressed(0,11)) cout << "Pressed 11" << endl;
                                if (sf::Joystick::isButtonPressed(0,12)) cout << "Pressed 12" << endl;
                                if (sf::Joystick::isButtonPressed(0,13)) cout << "Pressed 13" << endl;
                                cin.ignore();
                                cout << endl;
                            }
                            __quit = true;
                        }
                    }
                break;
                }
            case 6:
            {
                cout << "Controller Movement Starting." << endl;
                sleep(1);
                bool move = true;
                while (move)
                {
                    sf::Joystick::update();
                    Movement::MovementEngine _ME;
                    bool crouch = false;

                    if (sf::Joystick::isButtonPressed(0,7))
                    {
                        _ME.WalkForward(-1);
                        //control percentages
                    }
                    if (sf::Joystick::isButtonPressed(0,0))
                    {
                        _ME.RestingHeight = 6;
                        crouch = true;
                    }
                    else if (crouch)
                    {
                        _ME.RestingHeight = 12;
                        crouch = false;
                    }
                    if (sf::Joystick::isButtonPressed(0,1)) _ME.Jump();
                    if (sf::Joystick::isButtonPressed(0,3)) move = false;
                }
                break;
            }
            case 7:
                quit = true;
                break;
            default:
                break;
        }
    }
    cout << "That Concludes Movement Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}

static void vision()
{
    string _h = "";
    bool quit = false;
    while (quit == false)
    {
<<<<<<< Updated upstream
        cout << "Welcome to the HeistBOT Movement Testing Screen!\nWhat Do You Want to Test?\n\n   Option 1: Inverse Kinematics\n   Option 2: Single Motor Movement\n   Option 3: Leg Movement\n   Option 4: Walking\n\nSelect an Option (1,2,3) to Continue:\t";
=======
        cout << "Welcome to HeistBOT Vision Testing. What Do You Want to Test?\n\n   1:       \n   2:       \n   3:       \n   4:       \n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): "; //Add Placeholder Values
>>>>>>> Stashed changes
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
    cout << "That Concludes Vision Testing Testing.\n\nPress Any Button to Continue.";
    cin >> _h;
}

static void mapping()
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

static void intelligence()
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