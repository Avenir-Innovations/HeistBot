#include "Shape.h"
#include<array>

using namespace std;

bool Shape::IsInside(Vector2 pos)
{
	bool _in = true;
	bool left = false;
	bool right = false;
	
	if (pos.x <= vertices[0].x || pos.x <= vertices[1].x)
	{
		if (!((pos.y >= vertices[0].y && pos.y <= vertices[1].y) || (pos.y <= vertices[0].y && pos.y >= vertices[1].y))) _in = false;
		else left = true;
	}
	else if (pos.x >= vertices[0].x || pos.x >= vertices[1].x)
	{
		if (!((pos.y >= vertices[0].y && pos.y <= vertices[1].y) || (pos.y <= vertices[0].y && pos.y >= vertices[1].y))) _in = false;
		else right = true;
	}

	if ((pos.x <= vertices[1].x || pos.x <= vertices[2].x) && !left)
	{
		if (!((pos.y >= vertices[1].y && pos.y <= vertices[2].y) || (pos.y <= vertices[1].y && pos.y >= vertices[2].y))) _in = false;
		else left = true;
	}
	else if ((pos.x >= vertices[1].x || pos.x >= vertices[2].x) && !right)
	{
		if (!((pos.y >= vertices[1].y && pos.y <= vertices[2].y) || (pos.y <= vertices[1].y && pos.y >= vertices[2].y))) _in = false;
		else right = true;
	}

	if ((pos.x <= vertices[2].x || pos.x <= vertices[0].x) && !left)
	{
		if (!((pos.y >= vertices[2].y && pos.y <= vertices[0].y) || (pos.y <= vertices[2].y && pos.y >= vertices[0].y))) _in = false;
		else left = true;
	}
	else if ((pos.x >= vertices[2].x || pos.x >= vertices[0].x) && !right)
	{
		if (!((pos.y >= vertices[2].y && pos.y <= vertices[0].y) || (pos.y <= vertices[2].y && pos.y >= vertices[0].y))) _in = false;
		else right = true;
	}

	if (!(right && left)) _in = false;

	return _in;
}

bool Shape::IsInside(Vector2 pos, float tol) {
	bool _in = true;
	bool left = false;
	bool right = false;
	
	if ((pos.x - tol) <= vertices[0].x || (pos.x - tol) <= vertices[1].x)
	{
		if (!(((pos.y + tol) >= vertices[0].y && (pos.y - tol) <= vertices[1].y) || ((pos.y - tol) <= vertices[0].y && (pos.y + tol) >= vertices[1].y))) _in = false;
		else left = true;
	}
	else if ((pos.x + tol) >= vertices[0].x || (pos.x + tol) >= vertices[1].x)
	{
		if (!(((pos.y + tol) >= vertices[0].y && (pos.y - tol) <= vertices[1].y) || ((pos.y - tol) <= vertices[0].y && (pos.y + tol) >= vertices[1].y))) _in = false;
		else right = true;
	}

	if (((pos.x - tol) <= vertices[1].x || (pos.x - tol) <= vertices[2].x) && !left)
	{
		if (!(((pos.y + tol) >= vertices[1].y && (pos.y - tol) <= vertices[2].y) || ((pos.y - tol) <= vertices[1].y && (pos.y + tol) >= vertices[2].y))) _in = false;
		else left = true;
	}
	else if (((pos.x + tol) >= vertices[1].x || (pos.x + tol) >= vertices[2].x) && !right)
	{
		if (!(((pos.y + tol) >= vertices[1].y && (pos.y - tol) <= vertices[2].y) || ((pos.y - tol) <= vertices[1].y && (pos.y + tol) >= vertices[2].y))) _in = false;
		else right = true;
	}

	if (((pos.x - tol) <= vertices[2].x || (pos.x - tol) <= vertices[0].x) && !left)
	{
		if (!(((pos.y + tol) >= vertices[2].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[2].y && (pos.y + tol) >= vertices[0].y))) _in = false;
		else left = true;
	}
	else if (((pos.x + tol) >= vertices[2].x || (pos.x + tol) >= vertices[0].x) && !right)
	{
		if (!(((pos.y + tol) >= vertices[2].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[2].y && (pos.y + tol) >= vertices[0].y))) _in = false;
		else right = true;
	}

	if (!(right && left)) _in = false;

	return _in;
}

bool Shape::IsInside(Vector2 pos, float tolX, float tolY) {
	bool _in = true;
	bool left = false;
	bool right = false;
	
	if ((pos.x - tolX) <= vertices[0].x || (pos.x - tolX) <= vertices[1].x)
	{
		if (!(((pos.y + tolY) >= vertices[0].y && (pos.y - tolY) <= vertices[1].y) || ((pos.y - tolY) <= vertices[0].y && (pos.y + tolY) >= vertices[1].y))) _in = false;
		else left = true;
	}
	else if ((pos.x + tolX) >= vertices[0].x || (pos.x + tolX) >= vertices[1].x)
	{
		if (!(((pos.y + tolY) >= vertices[0].y && (pos.y - tolY) <= vertices[1].y) || ((pos.y - tolY) <= vertices[0].y && (pos.y + tolY) >= vertices[1].y))) _in = false;
		else right = true;
	}

	if (((pos.x - tolX) <= vertices[1].x || (pos.x - tolX) <= vertices[2].x) && !left)
	{
		if (!(((pos.y + tolY) >= vertices[1].y && (pos.y - tolY) <= vertices[2].y) || ((pos.y - tolY) <= vertices[1].y && (pos.y + tolY) >= vertices[2].y))) _in = false;
		else left = true;
	}
	else if (((pos.x + tolX) >= vertices[1].x || (pos.x + tolX) >= vertices[2].x) && !right)
	{
		if (!(((pos.y + tolY) >= vertices[1].y && (pos.y - tolY) <= vertices[2].y) || ((pos.y - tolY) <= vertices[1].y && (pos.y + tolY) >= vertices[2].y))) _in = false;
		else right = true;
	}

	if (((pos.x - tolX) <= vertices[2].x || (pos.x - tolX) <= vertices[0].x) && !left)
	{
		if (!(((pos.y + tolY) >= vertices[2].y && (pos.y - tolY) <= vertices[0].y) || ((pos.y - tolY) <= vertices[2].y && (pos.y + tolY) >= vertices[0].y))) _in = false;
		else left = true;
	}
	else if (((pos.x + tolX) >= vertices[2].x || (pos.x + tolX) >= vertices[0].x) && !right)
	{
		if (!(((pos.y + tolY) >= vertices[2].y && (pos.y - tolY) <= vertices[0].y) || ((pos.y - tolY) <= vertices[2].y && (pos.y + tolY) >= vertices[0].y))) _in = false;
		else right = true;
	}

	if (!(right && left)) _in = false;

	return _in;
}