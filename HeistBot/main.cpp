#include <cstdio>
#include <iostream>
#include <string>
#include "Vector2.h"
#include "MovementEngine.h"
#include "MappingEngine.h"
#include "Shape.h"
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
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        cout << "Welcome to HeistBOT Movement Testing. What Do You Want to Test?\n\n   1:       \n   2:       \n   3:       \n   4:       \n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): "; //Add Placeholder Values
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