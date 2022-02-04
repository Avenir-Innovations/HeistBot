#include "shape.h"
#include<array>

using namespace std;

bool shape::IsInside(Vector2 pos)
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