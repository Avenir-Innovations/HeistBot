#include "Shape.h"

using namespace CSS;

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
			cout << i;
			cout << "\n";

			float m = (get(vertices, i).y - get(vertices, i + 1).y) / (get(vertices, i).x - get(vertices, i + 1).x);
			float b = get(vertices, i).y - (get(vertices, i).x * m);

			
			if (get(vertices, i).x == get(vertices, i + 1).x)
			{
				if ((pos.x <= get(vertices, i).x) && !left)
				{
					cout << "left condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) left = true;
				}
				if ((pos.x >= get(vertices, i).x) && !right)
				{
					cout << "right condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) right = true;
				}
			}
			else
			{
				if ((pos.x <= ((pos.y - b) / m)) && !left)
				{
					cout << "left condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) left = true;
				}
				if ((pos.x >= ((pos.y - b) / m)) && !right)
				{
					cout << "right condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, i + 1).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, i + 1).y))) right = true;
				}
			}
			

			if ((pos.y <= ((pos.x * m) + b)) && !up)
			{
				cout << "up condition met\n";
				if (((pos.x >= get(vertices, i).x && pos.x <= get(vertices, i + 1).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, i + 1).x))) up = true;
			}
			if ((pos.y >= ((pos.x * m) + b)) && !down)
			{
				cout << "down condition met\n";
				if (((pos.x >= get(vertices, i).x && pos.x <= get(vertices, i + 1).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, i + 1).x))) down = true;
			}
		}
		else
		{
			cout << i;
			cout << "\n";
			cout << "approaching max\n";
			

			float m = (get(vertices, i).y - get(vertices, 0).y) / (get(vertices, i).x - get(vertices, 0).x);
			float b = get(vertices, i).y - (get(vertices, i).x * m);

			cout << ((pos.x * m) + b);
			cout << "\n";

			if (get(vertices, i).x == get(vertices, 0).x)
			{
				if ((pos.x <= get(vertices, i).x) && !left)
				{
					cout << "left condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) left = true;
				}
				if ((pos.x >= get(vertices, i).x) && !right)
				{
					cout << "right condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) right = true;
				}
			}
			else
			{
				if ((pos.x <= ((pos.y - b) / m)) && !left)
				{
					cout << "left condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) left = true;
				}
				if ((pos.x >= ((pos.y - b) / m)) && !right)
				{
					cout << "right condition met\n";
					if (((pos.y >= get(vertices, i).y && pos.y <= get(vertices, 0).y) || (pos.y <= get(vertices, i).y && pos.y >= get(vertices, 0).y))) right = true;
				}
			}

			if ((pos.y <= ((pos.x * m) + b)) && !up)
			{
				cout << "up condition met\n";
				if (((pos.x >= get(vertices, i).x && pos.x <= get(vertices, 0).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, 0).x))) up = true;
			}
			if ((pos.y >= ((pos.x * m) + b)) && !down)
			{
				cout << "down condition met\n";
				if (((pos.x >= get(vertices, i).x && pos.x <= get(vertices, 0).x) || (pos.x <= get(vertices, i).x && pos.x >= get(vertices, 0).x))) down = true;
			}
		}
	}

	if (right) cout << "right = true "; else cout << "right = false ";
	if (left) cout << "left = true "; else cout << "left = false ";
	if (up) cout << "up = true "; else cout << "up = false ";
	if (down) cout << "down = true\n"; else cout << "down = false\n";
	
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



bool Shape::IsOnEdge(Vector2 _pos)
{
	bool _b = false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (i != vertices.size() - 1)
		{
			float m = (get(vertices, i).y - get(vertices, i + 1).y) / (get(vertices, i).x - get(vertices, i + 1).x);
			float b = get(vertices, i).y - (get(vertices, i).x * m);

			if (get(vertices, i).x == get(vertices, i + 1).x && get(vertices, i).x == _pos.x) _b = true;
			else if (_pos.y = (_pos.x * m) + b) _b = true;
		}
		else
		{
			float m = (get(vertices, i).y - get(vertices, 0).y) / (get(vertices, i).x - get(vertices, 0).x);
			float b = get(vertices, i).y - (get(vertices, i).x * m);

			if (get(vertices, i).x == get(vertices, 0).x && get(vertices, i).x == _pos.x) _b = true;
			else if (_pos.y = (_pos.x * m) + b) _b = true;
		}
	}
	return _b;
}