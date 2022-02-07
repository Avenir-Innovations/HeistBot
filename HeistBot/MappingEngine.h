#pragma once
#include "Vector2.h"
#include "Shape.h"
#include <array>
#include <list>
#include <thread>
#include <algorithm>

class MappingEngine
{
	//(x,y) = x and y inches
private:
	list<Shape> polygons;
	list<Shape> gernatedPolygons;

	void GenerateShape (Vector2 _input);
	void CheckShapes ();
	void Update ();
	
public:
	Vector2 Position;
	list<Vector2> inputPoints;

	// look for nearest shape(s), check if inside of nearest shape(s), if not create new polygon using the new point.
	//TODO: Brainstorm How to extend new created shapes.

	void Initialize ();	
};

