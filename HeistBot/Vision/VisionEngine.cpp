#include "VisionEngine.h"

using namespace HeistBot;
using namespace Vision;
using namespace cv;

Vector2 VisionEngine::ReturnCoords(int x1, int y1, int x2, int y2)
{
  list<Vector2> coords = {Vector2(x1, x2), Vector2(y1, y2)};
  return coords;
}
