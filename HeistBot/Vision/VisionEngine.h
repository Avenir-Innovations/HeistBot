#pragma once
#include ".\..\C##\Vector2.h"
#include ".\..\C##\Shape.h"
#include ".\..\C##\ListsExtensions.h"
#include <array>
#include <list>
#include <thread>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace CSS;
using namespace cv;

namespace HeistBot
{
  namespace Vision
  {
    class VisionEngine
    {
      //(x,y) = x and y inches
    private:
      VideoCapture getStream();

    public:
      Vector2 Position;
      list<Vector2> ReturnCoords();

      int getGeneratedPolygonsCount() { return generatedPolygons.size(); }
      void generatedToMain()
      {
        polygons = generatedPolygons;
        generatedPolygons.clear();
      }

      // look for nearest shape(s), check if inside of nearest shape(s), if not create new polygon using the new point.
      // TODO: Brainstorm How to extend new created shapes.

      void Initialize();
    };
  }
}
