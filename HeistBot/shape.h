#pragma once
#include "Vector2.h"
#include <array>
#include <list>

using namespace std;
class Shape
{
public:
	list<Vector2> vertices;

	bool IsInside(Vector2 _pos);
	bool IsInside(Vector2 _pos, float tol);
	bool IsInside(Vector2 _pos, float tolX, float tolY);

	bool IsOnEdge(Vector2 _pos);
	bool IsOnEdge(Vector2 _pos, float tol);
	bool IsOnEdge(Vector2 _pos, float tolX, float tolY);
};

