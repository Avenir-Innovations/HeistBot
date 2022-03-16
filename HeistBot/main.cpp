#include <cstdio>
#include <iostream>
#include <string>
#include ".\Extras\Vector2.h"
#include ".\Movement\MovementEngine.h"
#include ".\Mapping\MappingEngine.h"
#include ".\Extras\Shape.h"
#include ".\Extras\Misc.h"

using namespace std;
using namespace HeistBot;
using namespace Extras;

int main()
{
    //Testing Inverse Kinematics + Vector2
    bool quit = false;
    while (quit == false)
    {
        cout << "Welcome to Tonight's Show! What Will It Be?\n\nOption 1: Test out tonight's Inverse Kinematics!\nOption 2: Create a Shape and Go Wild! You Deserve It.\nOption 3: Create many a Shape and Go Wild! You Deserve It.\nOption 4: Call it a Night and Head on Home.\n\nSelect an Option (1,2,3) to Continue:\t";
        string optionChosen = "";
        cin >> optionChosen;
        int selection;
        tryParse(optionChosen, &selection);
        int endThing = 1;
        switch (selection)
        {
            case 1:
                cout << "How Many Rounds?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Movement::MovementEngine _ME;
                    Vector2 pos;
                    cout << "Position, Ladies and Gentlemen! Any Position!\nX: ";
                    cin >> pos.x;
                    cout << "Y: ";
                    cin >> pos.y;
                    Vector2 angles = _ME.MotorAngles(pos);
                    cout << to_string(angles.x) + " , " + to_string(angles.y) + "\n";
                    endThing--;
                }
                break;
            case 2:
                cout << "How Many Rounds?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Shape _s;
                    Vector2 pos;
                    int vertexCount;
                    cout << "Let's Make you a shape. How Many Points, Good Sir?\n";
                    cin >> vertexCount;
                    cout << "Now Then, List Off Your Desired Boundries.\n";
                    if (vertexCount < 0) vertexCount *= -1;
                    while (vertexCount > 0)
                    {
                        cout << "\n";
                        pos = {0,0};
                        cout << ("Vertex " + to_string(_s.vertices.size() + 1) + "\n\tX:\t");
                        cin >> pos.x;
                        cout << "\tY:\t";
                        cin >> pos.y;
                        _s.vertices.push_back(pos);
                        vertexCount--;
                    }
                    pos = { 0,0 };
                    cout << ("Now Then, Give me a point and I'll tell you it's Fate.\n\tX:\t");
                    cin >> pos.x;
                    cout << "\tY:\t";
                    cin >> pos.y;
                    
                    bool yeahorNah = _s.IsInside(pos);

                    if (yeahorNah) cout << "Looks Like it's Safe and Sound.\n";
                    else cout << "Looks Like it's as Free as a Bird!\n";
                    endThing--;
                }
                break;
            case 3:
                cout << "How Many Rounds?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Mapping::MappingEngine _map;
                    Vector2 pos;
                    int vertexCount;
                    cout << "How Many Points, Good Sir?\n";
                    cin >> vertexCount;
                    cout << "Now Then, List Off Your Desired Points.\n";
                    if (vertexCount < 0) vertexCount *= -1;
                    while (vertexCount > 0)
                    {
                        cout << "\n";
                        pos = {0,0};
                        cout << ("Vertex " + to_string(_map.inputPoints.size() + 1) + "\n\tX:\t");
                        cin >> pos.x;
                        cout << "\tY:\t";
                        cin >> pos.y;
                        _map.inputPoints.push_back(pos);
                        vertexCount--;
                    }
                    pos = { 0,0 };
                    
                    _map.Initialize();

                    cout << "That Right there is a collection of " + to_string(_map.getGeneratedPolygonsCount()) + ".\n";
                    endThing--;
                }
                break;
            case 4:
                cout << "How Many Rounds?\n";
                cin >> endThing;
                if (endThing < 0) endThing *= -1;
                while (endThing > 0)
                {
                    Mapping::MappingEngine _map;
                    Vector2 pos;
                    int vertexCount;
                    cout << "How Many Points, Good Sir?\n";
                    cin >> vertexCount;
                    cout << "Now Then, List Off Your Desired Points.\n";
                    if (vertexCount < 0) vertexCount *= -1;
                    while (vertexCount > 0)
                    {
                        cout << "\n";
                        pos = {0,0};
                        cout << ("Vertex " + to_string(_map.inputPoints.size() + 1) + "\n\tX:\t");
                        cin >> pos.x;
                        cout << "\tY:\t";
                        cin >> pos.y;
                        _map.inputPoints.push_back(pos);
                        vertexCount--;
                    }
                    pos = { 0,0 };
                    _map.Initialize();
                    _map.generatedToMain();
                    cout << "Time to Start with the New Shapes! How Many Points, Good Sir?\n";
                    cin >> vertexCount;
                    cout << "Now Then, List Off Your Desired Points.\n";
                    if (vertexCount < 0) vertexCount *= -1;
                    while (vertexCount > 0)
                    {
                        cout << "\n";
                        pos = {0,0};
                        cout << ("Vertex " + to_string(_map.inputPoints.size() + 1) + "\n\tX:\t");
                        cin >> pos.x;
                        cout << "\tY:\t";
                        cin >> pos.y;
                        _map.inputPoints.push_back(pos);
                        vertexCount--;
                    }
                    pos = { 0,0 };
                    _map.Initialize();
                    


                    cout << "That Right there is a collection of " + to_string(_map.getGeneratedPolygonsCount()) + ".\n";
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
    cout << "That Concludes Today's Show!\n\nPress Any Button to Exit.";
    
    return 0;
}