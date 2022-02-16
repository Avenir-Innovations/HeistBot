#include "Shape.h"


using namespace std;

bool Shape::IsInside(Vector2 pos)
{
	bool _in = true;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;

	if (vertices.size() == 0)
	{
		cout << "vertices in shape Has a Size of 0";
		return false;
	}

	for (int i = 0; i < vertices.size(); i++) if (pos == get(vertices, i)) return true;

	for (int i = 0; i < vertices.size(); i++)
	{
		if (i != vertices.size() - 1)
		{
			if ((pos.x <= get(vertices, i).x || pos.x <= get(vertices, i + 1).x) && !left)
			{
				if (!((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) _in = false;
				else left = true;
			}
			else if ((pos.x >= get(vertices, i).x || pos.x >= get(vertices, i + 1).x) && !right)
			{
				if (!((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) _in = false;
				else right = true;
			}

			if ((pos.y <= get(vertices, i).y || pos.y <= get(vertices, i + 1).y) && !up)
			{
				if (!((pos.x >= get(vertices, i).x && pos.x <= get(vertices, i + 1).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, i + 1).x))) _in = false;
				else up = true;
			}
			else if ((pos.y >= get(vertices, i).y || pos.y >= get(vertices, i + 1).y) && !down)
			{
				if (!((pos.x >= get(vertices, i).x && pos.x <= get(vertices, i + 1).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, i + 1).x))) _in = false;
				else down = true;
			}
		}
		else
		{
			if ((pos.x <= get(vertices, i).x || pos.x <= get(vertices, 0).x) && !left)
			{
				if (!((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) _in = false;
				else left = true;
			}
			else if ((pos.x >= get(vertices, i).x || pos.x >= get(vertices, 0).x) && !right)
			{
				if (!((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) _in = false;
				else right = true;
			}

			if ((pos.y <= get(vertices, i).y || pos.y <= get(vertices, 0).y) && !up)
			{
				if (!((pos.x >= get(vertices, i).x && pos.x <= get(vertices, 0).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, 0).x))) _in = false;
				else up = true;
			}
			else if ((pos.y >= get(vertices, i).y || pos.y >= get(vertices, 0).y) && !down)
			{
				if (!((pos.x >= get(vertices, i).x && pos.x <= get(vertices, 0).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, 0).x))) _in = false;
				else down = true;
			}
		}
	}
	
	if (!(right && left && up && down)) _in = false;

	return _in;
}

bool Shape::IsInside(Vector2 pos, float tol) {
	bool _in = true;
	bool left = false;
	bool right = false;

	if (vertices.size() == 0) { cout << "vertices in shape Has a Size of 0"; return false; }

	for (int i = 0; i < vertices.size(); i++) if (pos == get(vertices, i)) return true;

	for (int i = 0; i < vertices.size(); i++)
	{
		if (i != vertices.size() - 1)
		{
			if (((pos.x - tol) <= get(vertices, i).x || (pos.x - tol) <= get(vertices, i + 1).x) && !left)
			{
				if (!(((pos.y + tol) >= get(vertices, i).y && (pos.y - tol) <= get(vertices, i + 1).y) || ((pos.y - tol) <= get(vertices, i).y && (pos.y + tol) >= get(vertices, i + 1).y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tol) >= get(vertices, i).x || (pos.x + tol) >= get(vertices, i + 1).x) && !right)
			{
				if (!(((pos.y + tol) >= get(vertices, i).y && (pos.y - tol) <= get(vertices, i + 1).y) || ((pos.y - tol) <= get(vertices, i).y && (pos.y + tol) >= get(vertices, i + 1).y))) _in = false;
				else right = true;
			}
		}
		else
		{
			if (((pos.x - tol) <= get(vertices, i).x || (pos.x - tol) <= get(vertices, 0).x) && !left)
			{
				if (!(((pos.y + tol) >= get(vertices, i).y && (pos.y - tol) <= get(vertices, 0).y) || ((pos.y - tol) <= get(vertices, i).y && (pos.y + tol) >= get(vertices, 0).y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tol) >= get(vertices, i).x || (pos.x + tol) >= get(vertices, 0).x) && !right)
			{
				if (!(((pos.y + tol) >= get(vertices, i).y && (pos.y - tol) <= get(vertices, 0).y) || ((pos.y - tol) <= get(vertices, i).y && (pos.y + tol) >= get(vertices, 0).y))) _in = false;
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
	
	if (vertices.size() == 0) { cout << "vertices in shape Has a Size of 0"; return false; }

	for (int i = 0; i < vertices.size(); i++) if (pos == get(vertices, i)) return true;

	for (int i = 0; i < vertices.size(); i++)
	{
		if (i != vertices.size() - 1)
		{
			if (((pos.x - tolX) <= get(vertices, i).x || (pos.x - tolX) <= get(vertices, i + 1).x) && !left)
			{
				if (!(((pos.y + tolY) >= get(vertices, i).y && (pos.y - tolY) <= get(vertices, i + 1).y) || ((pos.y - tolY) <= get(vertices, i).y && (pos.y + tolY) >= get(vertices, i + 1).y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tolX) >= get(vertices, i).x || (pos.x + tolX) >= get(vertices, i + 1).x) && !right)
			{
				if (!(((pos.y + tolY) >= get(vertices, i).y && (pos.y - tolY) <= get(vertices, i + 1).y) || ((pos.y - tolY) <= get(vertices, i).y && (pos.y + tolY) >= get(vertices, i + 1).y))) _in = false;
				else right = true;
			}
		}
		else
		{
			if (((pos.x - tolX) <= get(vertices, i).x || (pos.x - tolX) <= get(vertices, 0).x) && !left)
			{
				if (!(((pos.y + tolY) >= get(vertices, i).y && (pos.y - tolY) <= get(vertices, 0).y) || ((pos.y - tolY) <= get(vertices, i).y && (pos.y + tolY) >= get(vertices, 0).y))) _in = false;
				if (!(((pos.y + tolY) >= get(vertices, i).y && (pos.y - tolY) <= get(vertices, 0).y) || ((pos.y - tolY) <= get(vertices, i).y && (pos.y + tolY) >= get(vertices, 0).y))) _in = false;
				else left = true;
			}
			else if (((pos.x + tolX) >= get(vertices, i).x || (pos.x + tolX) >= get(vertices, 0).x) && !right)
			{
				if (!(((pos.y + tolY) >= get(vertices, i).y && (pos.y - tolY) <= get(vertices, 0).y) || ((pos.y - tolY) <= get(vertices, i).y && (pos.y + tolY) >= get(vertices, 0).y))) _in = false;
				else right = true;
			}
		}
	}

	if (!(right && left)) _in = false;

	return _in;
}