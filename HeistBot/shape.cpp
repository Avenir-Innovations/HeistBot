#include "Shape.h"
#include<array>

using namespace std;

bool Shape::IsInside(Vector2 pos)
{
	bool _in = true;
	bool left = false;
	bool right = false;

	if (size(vertices) == 0) { cout << "vertices in shape Has a Size of 0"; return false; }

	for (int i = 0; i < size(vertices); i++)
	{
		if (i != size(vertices) - i + 1)
		{
			if ((pos.x <= vertices[i].x || pos.x <= vertices[i + 1].x) && !left)
			{
				if (!((pos.y >= vertices[i].y && pos.y <= vertices[i + 1].y) || (pos.y <= vertices[i].y && pos.y >= vertices[i + 1].y))) _in = false;
				else left = true;
			}
			else if ((pos.x >= vertices[i].x || pos.x >= vertices[i + 1].x) && !right)
			{
				if (!((pos.y >= vertices[i].y && pos.y <= vertices[i + 1].y) || (pos.y <= vertices[i].y && pos.y >= vertices[i + 1].y))) _in = false;
				else right = true;
			}
		}
		else
		{
			if ((pos.x <= vertices[i].x || pos.x <= vertices[0].x) && !left)
			{
				if (!((pos.y >= vertices[i].y && pos.y <= vertices[0].y) || (pos.y <= vertices[i].y && pos.y >= vertices[0].y))) _in = false;
				else left = true;
			}
			else if ((pos.x >= vertices[i].x || pos.x >= vertices[0].x) && !right)
			{
				if (!((pos.y >= vertices[i].y && pos.y <= vertices[0].y) || (pos.y <= vertices[i].y && pos.y >= vertices[0].y))) _in = false;
				else right = true;
			}
		}
	}
	
	if (!(right && left)) _in = false;

	return _in;
}

bool Shape::IsInside(Vector2 pos, float tol) {
	bool _in = true;
	bool left = false;
	bool right = false;

	if (size(vertices) == 0) { cout << "vertices in shape Has a Size of 0"; return false; }

	for (int i = 0; i < size(vertices); i++)
	{
		if (i != size(vertices) - i + 1)
		{
			if (((pos.x - tol) <= vertices[i].x || (pos.x - tol) <= vertices[i + 1].x) && !left)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[i + 1].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[i + 1].y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tol) >= vertices[i].x || (pos.x + tol) >= vertices[i + 1].x) && !right)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[i + 1].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[i + 1].y))) _in = false;
				else right = true;
			}
		}
		else
		{
			if (((pos.x - tol) <= vertices[i].x || (pos.x - tol) <= vertices[0].x) && !left)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[0].y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tol) >= vertices[i].x || (pos.x + tol) >= vertices[0].x) && !right)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[0].y))) _in = false;
				else right = true;
			}
		}
	}

	if (!(right && left)) _in = false;

	return _in;
}

bool Shape::IsInside(Vector2 pos, float tolX, float tolY) {
	bool _in = true;
	bool left = false;
	bool right = false;
	
	if (size(vertices) == 0) { cout << "vertices in shape Has a Size of 0"; return false; }

	for (int i = 0; i < size(vertices); i++)
	{
		if (i != size(vertices) - i + 1)
		{
			if (((pos.x - tolX) <= vertices[i].x || (pos.x - tolX) <= vertices[i + 1].x) && !left)
			{
				if (!(((pos.y + tolY) >= vertices[i].y && (pos.y - tolY) <= vertices[i + 1].y) || ((pos.y - tolY) <= vertices[i].y && (pos.y + tolY) >= vertices[i + 1].y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tolX) >= vertices[i].x || (pos.x + tolX) >= vertices[i + 1].x) && !right)
			{
				if (!(((pos.y + tolY) >= vertices[i].y && (pos.y - tolY) <= vertices[i + 1].y) || ((pos.y - tolY) <= vertices[i].y && (pos.y + tolY) >= vertices[i + 1].y))) _in = false;
				else right = true;
			}
		}
		else
		{
			if (((pos.x - tol) <= vertices[i].x || (pos.x - tol) <= vertices[0].x) && !left)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[0].y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tol) >= vertices[i].x || (pos.x + tol) >= vertices[0].x) && !right)
			{
				if (!(((pos.y + tol) >= vertices[i].y && (pos.y - tol) <= vertices[0].y) || ((pos.y - tol) <= vertices[i].y && (pos.y + tol) >= vertices[0].y))) _in = false;
				else right = true;
			}
		}
	}

	if (!(right && left)) _in = false;

	return _in;
}