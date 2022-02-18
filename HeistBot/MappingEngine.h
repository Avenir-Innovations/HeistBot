#pragma once
#include "Vector2.h"
#include "Shape.h"
#include "ListsExtensions.h"
#include <array>
#include <list>
#include <thread>
#include <algorithm>

using namespace std;

class MappingEngine
{
	//(x,y) = x and y inches
private:
	list<Shape> polygons;
	list<Vector2> allVertices;
	list<Shape> genernatedPolygons;

	void GenerateShapes ();
	void CheckShapes ();
	void Update ();
	
public:
	Vector2 Position;
	list<Vector2> inputPoints;

	// look for nearest shape(s), check if inside of nearest shape(s), if not create new polygon using the new point.
	//TODO: Brainstorm How to extend new created shapes.

	void Initialize ();	
};

