#include <cstdio>
#include <iostream>
#include <string>
#include ".\C##\Vector2.h"
#include ".\Movement\MovementEngine.h"
#include ".\Mapping\MappingEngine.h"
#include ".\C##\Shape.h"
#include ".\C##\Misc.h"

using namespace std;
using namespace HeistBot;
using namespace CSS;

int main()
{
    bool quit = false;
    string _h = "";
    while (quit == false)
    {
        //cout << "Welcome to Testing For HeistBOT. What Are You Testing?\n\n   1: Movement\n   2: Vision\n 3: Mapping\n   4: Intelligence\n   5: Quit\n\nChoose an Option (1, 2, 3, 4, 5): ";
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
    cout << "That Concludes Today's Testing.\n\nPress Any Button to Exit.";
    cin >> _h;
    
    return 0;
}