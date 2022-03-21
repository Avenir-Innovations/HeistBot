#pragma once
#include ".\..\C##\Vector2.h"
#include ".\..\C##\Shape.h"
#include ".\..\C##\ListsExtensions.h"
#include <array>
#include <list>
#include <thread>
#include <algorithm>

using namespace std;
using namespace CSS;

namespace HeistBot
{
	namespace Mapping
	{
		class MappingEngine
		{
			//(x,y) = x and y inches
			private:
				list<Shape> polygons;
				list<Vector2> allVertices;
				list<Shape> generatedPolygons;

				float averageDistance ();

				void GenerateShapes ();
				void CheckShapes ();
				void Update ();
				
			public:
				Vector2 Position;
				list<Vector2> inputPoints;

				int getGeneratedPolygonsCount () { return generatedPolygons.size(); }
				void generatedToMain () { polygons = generatedPolygons; generatedPolygons.clear(); }

				// look for nearest shape(s), check if inside of nearest shape(s), if not create new polygon using the new point.
				//TODO: Brainstorm How to extend new created shapes.

				void Initialize ();	
		};
	}
}

