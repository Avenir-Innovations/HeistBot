#pragma once
#include "Vector2.h"
#include "Shape.h"
#include "ListsExtensions.h"
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
      Vector2 Position; //Leftover from MappingEngine Ctrl+C, Ctrl+V
      list<Vector2> ReturnCoords();

      int getGeneratedPolygonsCount() { return generatedPolygons.size(); } //Leftover from MappingEngine Ctrl+C, Ctrl+V
      void generatedToMain() //Leftover from MappingEngine Ctrl+C, Ctrl+V
      {
        polygons = generatedPolygons;
        generatedPolygons.clear();
      }

      void Initialize();
    };
  }
}
