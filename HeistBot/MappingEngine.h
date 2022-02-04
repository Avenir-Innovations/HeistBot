#pragma once
#include "Vector2.h"
#include "Shape.h"
#include <array>
#include <list>
#include<thread>
//std::thread thread_object(callable)

class MappingEngine
{
public:
	Vector2 Position;
	list<Vector2> inputPoints;

	// look for nearest shape(s), check if inside of nearest shape(s), if not create new polygon using the new point.
	//TODO: Brainstorm How to extend new created shapes.
private:
	list<Shape> polygons;
	
};

