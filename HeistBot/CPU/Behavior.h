#pragma once
#include <array>
#include <list>
#include ".\..\C##\Vector2.h"

using namespace std;
using namespace CSS;

namespace HeistBot
{
	namespace CentralProcessing
	{
		class Behavior
		{
			public:
				list<Vector2> Points;
				list<Vector2> Times;
				list<Vector2> Directions;
		};
	}
}



