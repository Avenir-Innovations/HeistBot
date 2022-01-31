#pragma once
#include "Vector2.h"

using namespace std;
class shape
{
public:
	//making everything triangles
	array<Vector2, 3> vertices[];

	bool IsInside(Vector2 _pos);
	bool IsInside(Vector2 _pos, float tol);

	bool IsOnEdge(Vector2 _pos);
	bool IsOnEdge(Vector2 _pos, float tol);
};

